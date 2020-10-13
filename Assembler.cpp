#include <iostream>
#include <unordered_map>
#include <string>
#include <chrono>
#include <fstream>
#include <sstream> // for string streams

#include "types/JSObject.hpp"

#include "tables/addr_gen.hpp"

#include "functions/opcode_type.hpp"
#include "functions/funct_type.hpp"
#include "functions/format_type.hpp"
#include "functions/addr_type.hpp"
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

string generate_R_type(string prog_line, string format)
{
    string result = "00000000000000000000";
    vector<string> sstring = split_string(prog_line, ",");
    if (sstring.size() > 2)
    {
        for (int i = 0; i < sstring.size(); i++)
        {
            string code = addr_of(trim_string(sstring[i]));
            if (code.compare("") == 0)
            {
                ostringstream str1;
                str1 << decimalToBinary(stoi(trim_string(sstring[i])));
                sstring[i] = str1.str();
            }
            else
                sstring[i] = code;
        }

        result.replace(0, 5, sstring[1]);
        result.replace(6, 5, sstring[2]);
        result.replace(11, 5, sstring[0]);
    }
    else if (sstring.size() == 2)
    {
        for (int i = 0; i < sstring.size(); i++)
        {
            string code = addr_of(trim_string(sstring[i]));
            if (code.compare("") == 0)
            {
                ostringstream str1;
                str1 << decimalToBinary(stoi(trim_string(sstring[i])));
                sstring[i] = str1.str();
            }
            else
                sstring[i] = code;
        }

        result.replace(0, 5, sstring[0]);
        result.replace(6, 5, sstring[1]);
    }
    else
        return "error";
    return result;
}

string generate_binary_code(string prog_line)
{
    string result = "00000000000000000000000000000000";
    JSObject codes = MNEMONIC_codes(prog_line);

    string format = codes["format"];
    string opcode = codes["opcode"];
    string funct = codes["funct"];

    result.replace(0, 5, opcode);
    if (format.compare("R") == 0)
    {
        result.replace(26, 31, funct);
        size_t MNEMONIC_end_pos = prog_line.find(" ");
        string code = generate_R_type(prog_line.substr(MNEMONIC_end_pos + 1, prog_line.size()), format);
        result.replace(6, code.size() - 1, code);
    }
    else if (format.compare("I") == 0)
    {
        // TODO
        return "TODO";
    }
    else if (format.compare("J") == 0)
    {
        size_t MNEMONIC_end_pos = prog_line.find(" ");
        ostringstream str1;
        string code = prog_line.substr(MNEMONIC_end_pos + 1, prog_line.size());
        vector<string> sstring = split_string(code, ",");

        str1 << decimalToBinary(stoi(trim_string(sstring[1])));
        string bincode = str1.str();
        result.replace(32 - (bincode.size() - 1), 31, bincode);
    }
    else
        return "error";
    return result;
}

int main(int argc, char *argv[])
{
    auto start = chrono::high_resolution_clock::now();

    string filename = argv[1];
    ifstream input_file(filename);
    string output_filename = "prog_bin.txt";
    output_filename.replace(4, 1, split_string(filename, "/")[split_string(filename, "/").size() - 1].substr(4, 1));

    ofstream output_file("output/" + output_filename);
    if (input_file.is_open() && output_file.is_open())
    {
        string prog_line;
        while (getline(input_file, prog_line))
        {
            string bin = generate_binary_code(prog_line);
            output_file << bin << " (" << bin2hex(bin) << ", " << prog_line << ")" << endl;
            cout << bin << " (" << bin2hex(bin) << ", " << prog_line << ")" << endl;
        }
        input_file.close();
        output_file.close();
    }
    else
        cout << "Unable to open file" << endl;

    auto stop = chrono::high_resolution_clock::now();
    cout << "\nDone in " << ((stop - start).count()) / 1000 << " ms!\n";
    return 0;
}
