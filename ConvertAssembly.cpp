#include <iostream>
#include <unordered_map>
#include <string>
#include <chrono>
#include <fstream>

#include "functions/split_string.hpp"

using namespace std;

string generate_asm_code(string prog_line)
{
    return "Cool!";
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
