#include<iostream>
#include<chrono> 

#include "tables/addr_gen.hpp"
#include "tables/opcode_gen.hpp"

using namespace std;

int main () {
    cout << "Initializing...\n";
    auto start = chrono::high_resolution_clock::now();
    JSObject addr = addrGen();
    JSObject opcode = opcodeGen();
    auto stop = chrono::high_resolution_clock::now();
    cout << "Initailized. Took " << (stop - start).count() << " microseconds!\n";

    string prog_line = "addi $s0, $zero, 10";
    return 0;
}
