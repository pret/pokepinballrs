# Expects an input file with lines of the form 'SYMBOL ADDRESS'
#

BEGIN {
    prevAddress = "";
}
/\w+ \w+/ {
    symbol = $1;
    address = $2;

    # Output space before
    if (prevAddress != "") {
        space = address - prevAddress;
        if (space < 0) {
            print("error: list is not sorted" > /dev/stderr);
            exit(1);
        }
        printf("\t.space 0x%X\n", space);
    }
    
    prevAddress = address;

    # Output label
    print(symbol ": @ " address);

}