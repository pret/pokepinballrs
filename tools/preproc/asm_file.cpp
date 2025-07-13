// Copyright(c) 2016 YamaArashi
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include <cstdio>
#include <cstdarg>
#include <stdexcept>
#include "preproc.h"
#include "asm_file.h"
#include "char_util.h"
#include "utf8.h"
#include "string_parser.h"

AsmFile::AsmFile(std::string filename) : m_filename(filename)
{
    FILE *fp = std::fopen(filename.c_str(), "rb");

    if (fp == NULL)
        FATAL_ERROR("Failed to open \"%s\" for reading.\n", filename.c_str());

    std::fseek(fp, 0, SEEK_END);

    m_size = std::ftell(fp);

    if (m_size < 0)
        FATAL_ERROR("File size of \"%s\" is less than zero.\n", filename.c_str());

    m_buffer = new char[m_size + 1];

    std::rewind(fp);

    if (std::fread(m_buffer, m_size, 1, fp) != 1)
        FATAL_ERROR("Failed to read \"%s\".\n", filename.c_str());

    m_buffer[m_size] = 0;

    std::fclose(fp);

    m_pos = 0;
    m_lineNum = 1;
    m_lineStart = 0;

    RemoveComments();
}

AsmFile::AsmFile(AsmFile&& other) : m_filename(std::move(other.m_filename))
{
    m_buffer = other.m_buffer;
    m_pos = other.m_pos;
    m_size = other.m_size;
    m_lineNum = other.m_lineNum;
    m_lineStart = other.m_lineStart;

    other.m_buffer = nullptr;
}

AsmFile::~AsmFile()
{
    delete[] m_buffer;
}

// Removes comments to simplify further processing.
// It stops upon encountering a null character,
// which may or may not be the end of file marker.
// If it's not, the error will be caught later.
void AsmFile::RemoveComments()
{
    long pos = 0;
    char stringChar = 0;

    for (;;)
    {
        if (m_buffer[pos] == 0)
            return;

        if (stringChar != 0)
        {
            if (m_buffer[pos] == '\\' && m_buffer[pos + 1] == stringChar)
            {
                pos += 2;
            }
            else
            {
                if (m_buffer[pos] == stringChar)
                    stringChar = 0;
                pos++;
            }
        }
        else if (m_buffer[pos] == '@' && (pos == 0 || m_buffer[pos - 1] != '\\'))
        {
            while (m_buffer[pos] != '\n' && m_buffer[pos] != 0)
                m_buffer[pos++] = ' ';
        }
        else if (m_buffer[pos] == '/' && m_buffer[pos + 1] == '*')
        {
            m_buffer[pos++] = ' ';
            m_buffer[pos++] = ' ';

            for (;;)
            {
                if (m_buffer[pos] == 0)
                    return;

                if (m_buffer[pos] == '*' && m_buffer[pos + 1] == '/')
                {
                    m_buffer[pos++] = ' ';
                    m_buffer[pos++] = ' ';
                    break;
                }
                else
                {
                    if (m_buffer[pos] != '\n')
                        m_buffer[pos] = ' ';
                    pos++;
                }
            }
        }
        else
        {
            if (m_buffer[pos] == '"' || m_buffer[pos] == '\'')
                stringChar = m_buffer[pos];
            pos++;
        }
    }
}

// Checks if we're at a particular directive and if so, consumes it.
// Returns whether the directive was found.
bool AsmFile::CheckForDirective(std::string name)
{
    long i;
    long length = static_cast<long>(name.length());

    for (i = 0; i < length && m_pos + i < m_size; i++)
        if (name[i] != m_buffer[m_pos + i])
            return false;

    if (i < length)
        return false;

    m_pos += length;

    return true;
}

// Checks if we're at a known directive and if so, consumes it.
// Returns which directive was found.
Directive AsmFile::GetDirective()
{
    SkipWhitespace();

    if (CheckForDirective(".include"))
        return Directive::Include;
    else if (CheckForDirective(".string"))
        return Directive::String;
    else if (CheckForDirective(".braille"))
        return Directive::Braille;
    else if (CheckForDirective(".dexName"))
        return Directive::DexName;
    else if (CheckForDirective(".dexCategory"))
        return Directive::DexCategory;
    else if (CheckForDirective(".dexText"))
        return Directive::DexText;
    else
        return Directive::Unknown;
}

// Checks if we're at label that ends with '::'.
// Returns the name if so and an empty string if not.
std::string AsmFile::GetGlobalLabel()
{
    long start = m_pos;
    long pos = m_pos;

    if (IsIdentifierStartingChar(m_buffer[pos]))
    {
        pos++;

        while (IsIdentifierChar(m_buffer[pos]))
            pos++;
    }

    if (m_buffer[pos] == ':' && m_buffer[pos + 1] == ':')
    {
        m_pos = pos + 2;
        ExpectEmptyRestOfLine();
        return std::string(&m_buffer[start], pos - start);
    }

    return std::string();
}

// Skips tabs and spaces.
void AsmFile::SkipWhitespace()
{
    while (m_buffer[m_pos] == '\t' || m_buffer[m_pos] == ' ')
        m_pos++;
}

// Reads include path.
std::string AsmFile::ReadPath()
{
    SkipWhitespace();

    if (m_buffer[m_pos] != '"')
        RaiseError("expected file path");

    m_pos++;

    int length = 0;
    long startPos = m_pos;

    while (m_buffer[m_pos] != '"')
    {
        unsigned char c = m_buffer[m_pos++];

        if (c == 0)
        {
            if (m_pos >= m_size)
                RaiseError("unexpected EOF in include string");
            else
                RaiseError("unexpected null character in include string");
        }

        if (!IsAsciiPrintable(c))
            RaiseError("unexpected character '\\x%02X' in include string", c);

        // Don't bother allowing any escape sequences.
        if (c == '\\')
        {
            c = m_buffer[m_pos];
            RaiseError("unexpected escape '\\%c' in include string", c);
        }

        length++;

        if (length > kMaxPath)
            RaiseError("path is too long");
    }

    m_pos++; // Go past the right quote.

    ExpectEmptyRestOfLine();

    return std::string(&m_buffer[startPos], length);
}

// Reads a charmap string.
int AsmFile::ReadString(unsigned char* s)
{
    SkipWhitespace();

    int length;
    StringParser stringParser(m_buffer, m_size);

    try
    {
        m_pos += stringParser.ParseString(m_pos, s, length);
    }
    catch (std::runtime_error& e)
    {
        RaiseError(e.what());
    }

    SkipWhitespace();

    if (ConsumeComma())
    {
        SkipWhitespace();
        int padLength = ReadPadLength();

        while (length < padLength)
        {
            s[length++] = 0;
        }
    }

    ExpectEmptyRestOfLine();

    return length;
}

int AsmFile::ReadBraille(unsigned char* s)
{
    static std::map<char, unsigned char> encoding =
    {
        { 'A', 0x01 },
        { 'B', 0x05 },
        { 'C', 0x03 },
        { 'D', 0x0B },
        { 'E', 0x09 },
        { 'F', 0x07 },
        { 'G', 0x0F },
        { 'H', 0x0D },
        { 'I', 0x06 },
        { 'J', 0x0E },
        { 'K', 0x11 },
        { 'L', 0x15 },
        { 'M', 0x13 },
        { 'N', 0x1B },
        { 'O', 0x19 },
        { 'P', 0x17 },
        { 'Q', 0x1F },
        { 'R', 0x1D },
        { 'S', 0x16 },
        { 'T', 0x1E },
        { 'U', 0x31 },
        { 'V', 0x35 },
        { 'W', 0x2E },
        { 'X', 0x33 },
        { 'Y', 0x3B },
        { 'Z', 0x39 },
        { ' ', 0x00 },
        { ',', 0x04 },
        { '.', 0x2C },
        { '$', 0xFF },
    };

    SkipWhitespace();

    int length = 0;

    if (m_buffer[m_pos] != '"')
        RaiseError("expected braille string literal");

    m_pos++;

    while (m_buffer[m_pos] != '"')
    {
        if (length == kMaxStringLength)
            RaiseError("mapped string longer than %d bytes", kMaxStringLength);

        if (m_buffer[m_pos] == '\\' && m_buffer[m_pos + 1] == 'n')
        {
            s[length++] = 0xFE;
            m_pos += 2;
        }
        else
        {
            char c = m_buffer[m_pos];

            if (encoding.count(c) == 0)
            {
                if (IsAsciiPrintable(c))
                    RaiseError("character '%c' not valid in braille string", m_buffer[m_pos]);
                else
                    RaiseError("character '\\x%02X' not valid in braille string", m_buffer[m_pos]);
            }

            s[length++] = encoding[c];
            m_pos++;
        }
    }

    m_pos++; // Go past the right quote.

    ExpectEmptyRestOfLine();

    return length;
}

int AsmFile::ReadDexString(unsigned short* s, uint8_t targetLength, bool padLeft = false)
{
    // Sample dexEncoding map
    static std::map<char, unsigned short> dexEncoding = 
    {
        { ' ', 0x0000 },
        { '-', 0x2826 }, { U'♀', 0x2846 }, { U'♂', 0x2866 },
        { '0', 0x2886 }, { '1', 0x28A3 }, { '2', 0x28C6 }, { '3', 0x28E6 },
        { '4', 0x2906 }, { '5', 0x2926 }, { '6', 0x2946 }, { '7', 0x2966 },
        { '8', 0x2986 }, { '9', 0x29A6 }, { U'—', 0x29C6 },

        { 'A', 0x29E6 }, { 'B', 0x2A06 }, { 'C', 0x2A26 }, { 'D', 0x2A46 },
        { 'E', 0x2A66 }, { 'F', 0x2A86 }, { 'G', 0x2AA6 }, { 'H', 0x2AC6 },
        { 'I', 0x2AE2 }, { 'J', 0x2B06 }, { 'K', 0x2B26 }, { 'L', 0x2B46 },
        { 'M', 0x2B66 }, { 'N', 0x2B86 }, { 'O', 0x2BA6 }, { 'P', 0x2BC6 },
        { 'Q', 0x2BE6 }, { 'R', 0x3006 }, { 'S', 0x3026 }, { 'T', 0x3046 },
        { 'U', 0x3066 }, { 'V', 0x3086 }, { 'W', 0x30A6 }, { 'X', 0x30C6 },
        { 'Y', 0x30E6 }, { 'Z', 0x3106 },

        { 'a', 0x3126 }, { 'b', 0x3146 }, { 'c', 0x3166 }, { 'd', 0x3186 },
        { 'e', 0x31A6 }, { 'f', 0x31C6 }, { 'g', 0x31E6 }, { 'h', 0x3206 },
        { 'i', 0x3222 }, { 'j', 0x3246 }, { 'k', 0x3266 }, { 'l', 0x3283 },
        { 'm', 0x32A6 }, { 'n', 0x32C5 }, { 'o', 0x32E6 }, { 'p', 0x3306 },
        { 'q', 0x3326 }, { 'r', 0x3345 }, { 's', 0x3366 }, { 't', 0x3386 },
        { 'u', 0x33A6 }, { 'v', 0x33C6 }, { 'w', 0x33E6 }, { 'x', 0x3806 },
        { 'y', 0x3826 }, { 'z', 0x3846 },

        { U'ˎ', 0x3866 }, { U'˳', 0x3886 }, { U'╔', 0x38A6 }, { U'╝', 0x38C6 },
        { U'×', 0x38E6 }, { U'“', 0x3926 }, { U'”', 0x3906 }, { '!', 0x3942 },
        { '?', 0x3968 }, { ':', 0x3984 }, { ';', 0x39A4 }, { ',', 0x39C4 },
        { '.', 0x39E4 }, { U'•', 0x3A04 }, { '(', 0x3A26 }, { ')', 0x3A46 },
        { '~', 0x3A68 }, { U'▼', 0x3A88 }, { U'é', 0x3AA6 }, { '`', 0x3AC3 },
        { U'´', 0x3AE4 }, { '#', 0x3B06 },
    };

    SkipWhitespace();

    if (m_buffer[m_pos] != '"')
        RaiseError("expected dex string literal");

    m_pos++;

    std::vector<unsigned short> temp;

    while (m_buffer[m_pos] != '"')
    {
        if (temp.size() == targetLength)
            RaiseError("mapped string longer than %d entries", targetLength);

        char c = m_buffer[m_pos];

        if (dexEncoding.count(c) == 0)
        {
            if (IsAsciiPrintable(c))
                RaiseError("character '%c' not valid in dex string", c);
            else
                RaiseError("character '\\x%02X' not valid in dex string", static_cast<unsigned char>(c));
        }

        temp.push_back(dexEncoding[c]);
        m_pos++;    
    }

    m_pos++; // Past closing quote
    ExpectEmptyRestOfLine();

    // Padding logic
    int actualLength = static_cast<int>(temp.size());

    int padCount = targetLength - actualLength;

    // Fill output with padding + data
    int pos = 0;
    if (padLeft)
    {
        for (int i = 0; i < padCount; ++i) s[pos++] = 0x0000;
        for (unsigned short val : temp) s[pos++] = val;
    }
    else
    {
        for (unsigned short val : temp) s[pos++] = val;
        for (int i = 0; i < padCount; ++i) s[pos++] = 0x0000;
    }

    return targetLength;
}

// If we're at a comma, consumes it.
// Returns whether a comma was found.
bool AsmFile::ConsumeComma()
{
    if (m_buffer[m_pos] == ',')
    {
        m_pos++;
        return true;
    }

    return false;
}

// Converts digit character to numerical value.
static int ConvertDigit(char c, int radix)
{
    int digit;

    if (c >= '0' && c <= '9')
        digit = c - '0';
    else if (c >= 'A' && c <= 'F')
        digit = 10 + c - 'A';
    else if (c >= 'a' && c <= 'f')
        digit = 10 + c - 'a';
    else
        return -1;

    return (digit < radix) ? digit : -1;
}

// Reads an integer. If the integer is greater than maxValue, it returns -1.
int AsmFile::ReadPadLength()
{
    if (!IsAsciiDigit(m_buffer[m_pos]))
        RaiseError("expected integer");

    int radix = 10;

    if (m_buffer[m_pos] == '0' && m_buffer[m_pos + 1] == 'x')
    {
        radix = 16;
        m_pos += 2;
    }

    unsigned n = 0;
    int digit;

    while ((digit = ConvertDigit(m_buffer[m_pos], radix)) != -1)
    {
        n = n * radix + digit;

        if (n > kMaxStringLength)
            RaiseError("pad length greater than maximum length (%d)", kMaxStringLength);

        m_pos++;
    }

    return n;
}

// Outputs the current line and moves to the next one.
void AsmFile::OutputLine()
{
    while (m_buffer[m_pos] != '\n' && m_buffer[m_pos] != 0)
        m_pos++;

    if (m_buffer[m_pos] == 0)
    {
        if (m_pos >= m_size)
        {
            RaiseWarning("file doesn't end with newline");
            puts(&m_buffer[m_lineStart]);
        }
        else
        {
            RaiseError("unexpected null character");
        }
    }
    else
    {
        m_buffer[m_pos] = 0;
        puts(&m_buffer[m_lineStart]);
        m_buffer[m_pos] = '\n';
        m_pos++;
        m_lineStart = m_pos;
        m_lineNum++;
    }
}

// Asserts that the rest of the line is empty and moves to the next one.
void AsmFile::ExpectEmptyRestOfLine()
{
    SkipWhitespace();

    if (m_buffer[m_pos] == 0)
    {
        if (m_pos >= m_size)
            RaiseWarning("file doesn't end with newline");
        else
            RaiseError("unexpected null character");
    }
    else if (m_buffer[m_pos] == '\n')
    {
        m_pos++;
        m_lineStart = m_pos;
        m_lineNum++;
    }
    else if (m_buffer[m_pos] == '\r')
    {
        RaiseError("only Unix-style LF newlines are supported");
    }
    else
    {
        RaiseError("junk at end of line");
    }
}

// Checks if we're at the end of the file.
bool AsmFile::IsAtEnd()
{
    return (m_pos >= m_size);
}

// Output the current location to set gas's logical file and line numbers.
void AsmFile::OutputLocation()
{
    std::printf("# %ld \"%s\"\n", m_lineNum, m_filename.c_str());
}

// Reports a diagnostic message.
void AsmFile::ReportDiagnostic(const char* type, const char* format, std::va_list args)
{
    const int bufferSize = 1024;
    char buffer[bufferSize];
    std::vsnprintf(buffer, bufferSize, format, args);
    std::fprintf(stderr, "%s:%ld: %s: %s\n", m_filename.c_str(), m_lineNum, type, buffer);
}

#define DO_REPORT(type)                   \
do                                        \
{                                         \
    std::va_list args;                    \
    va_start(args, format);               \
    ReportDiagnostic(type, format, args); \
    va_end(args);                         \
} while (0)

// Reports an error diagnostic and terminates the program.
void AsmFile::RaiseError(const char* format, ...)
{
    DO_REPORT("error");
    std::exit(1);
}

// Reports a warning diagnostic.
void AsmFile::RaiseWarning(const char* format, ...)
{
    DO_REPORT("warning");
}
