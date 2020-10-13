#include <iostream>
#include <vector>

#include "opcode_type.hpp"
#include "../tables/opcode_gen.hpp"

using namespace std;

JSObject opcode_table = opcodeGen();

string opcode_of(string MNEMONIC)
{
    return opcode_table[MNEMONIC];
}
