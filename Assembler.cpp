#include <iostream>
#include <chrono>

#include "functions/opcode_type.hpp"

using namespace std;

int main()
{
    auto start = chrono::high_resolution_clock::now();

    string prog_line = "addi $s0, $zero, 10";
    auto opcode = opcode_of(prog_line);

    auto stop = chrono::high_resolution_clock::now();
    cout << "\nTook " << (stop - start).count() << " microseconds!\n";
    return 0;
}
