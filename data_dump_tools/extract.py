import sys

def extract_bytes(input_file, output_file, start, length):
    with open(input_file, 'rb') as f:
        f.seek(start)
        data = f.read(length)
    with open(output_file, 'wb') as f:
        f.write(data)

if __name__ == "__main__":
    if len(sys.argv) != 5:
        print(f"Usage: {sys.argv[0]} <input_file> <output_file> <start> <length>")
        sys.exit(1)
    input_file = sys.argv[1]
    output_file = sys.argv[2]
    start = int(sys.argv[3], 0)
    length = int(sys.argv[4], 0)
    extract_bytes(input_file, output_file, start, length)
