#include <iostream>
#include <unordered_map>
#include <chrono>

#include "types/JSObject.hpp"

#include "functions/opcode_type.hpp"
#include "functions/funct_type.hpp"
#include "functions/format_type.hpp"
#include "functions/split_string.hpp"

using namespace std;

JSObject MNEMONIC_codes(string prog_line)
{
    vector<string> sstring = split_string(prog_line, " ");
    string MNEMONIC = sstring[0];
    JSObject result;
    result["opcode"] = opcode_of(MNEMONIC);
    result["funct"] = funct_of(MNEMONIC);
    result["format"] = format_of(MNEMONIC);
    return result;
}

int main()
{
    auto start = chrono::high_resolution_clock::now();

    string prog_line = "add $s0, $zero, 10";
    JSObject codes = MNEMONIC_codes(prog_line);
    cout << codes["opcode"] << codes["format"] << codes["funct"] << endl;

    auto stop = chrono::high_resolution_clock::now();
    cout << "\nTook " << (stop - start).count() << " microseconds!\n";
    return 0;
}
