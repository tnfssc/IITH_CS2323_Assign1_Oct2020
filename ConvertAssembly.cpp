#include <iostream>
#include <unordered_map>
#include <string>
#include <chrono>
#include <fstream>

#include "functions/split_string.hpp"
#include "functions/format_type.hpp"
#include "functions/funct_type.hpp"
#include "functions/addr_type.hpp"
#include "functions/opcode_type.hpp"

using namespace std;

string generate_asm_code(string prog_line)
{
    string result;
    string opcode = prog_line.substr(0, 6);
    string format = format_of(opcode);
    if (format.compare("R") == 0)
    {
        string funct = prog_line.substr(27, 6);
        result.append(funct_reverse_of(funct));
        result.append(" ");
        result.append(addr_reverse_of(prog_line.substr(6 + 11, 5)));
        result.append(", ");
        result.append(addr_reverse_of(prog_line.substr(6 + 0, 5)));
        result.append(", ");
        result.append(addr_reverse_of(prog_line.substr(6 + 6, 5)));
    }
    else if (format.compare("I") == 0)
    {
        result = "TODO";
    }
    else if (format.compare("J") == 0)
    {
        string funct = prog_line.substr(0, 6);
        result.append(opcode_reverse_of(funct));
        result.append(" ");
        string label = prog_line.substr(6);
        result.append(binaryToDecimalStrings(label));
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
    string output_filename = "bin_prog.asm";
    output_filename.replace(3, 1, split_string(filename, "/")[split_string(filename, "/").size() - 1].substr(4, 1));

    ofstream output_file("output/" + output_filename);
    if (input_file.is_open() && output_file.is_open())
    {
        string prog_line;
        while (getline(input_file, prog_line))
        {
            string asmcode = generate_asm_code(split_string(prog_line, " ")[0]);
            output_file << asmcode << endl;
            cout << asmcode << endl;
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
