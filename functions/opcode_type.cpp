#include <iostream>
#include <vector>

#include "opcode_type.hpp"
#include "../tables/opcode_gen.hpp"

using namespace std;

JSObject opcode_table = opcodeGen();

JSObject addr_reverseGen()
{
    JSObject reverseMap;
    for (auto it = opcode_table.begin(); it != opcode_table.end(); it++)
        reverseMap[it->second] = it->first;
    return reverseMap;
}

JSObject opcode_reverse_table = addr_reverseGen();

string opcode_of(string MNEMONIC)
{
    return opcode_table[MNEMONIC];
}

string opcode_reverse_of(string MNEMONIC)
{
    return opcode_table[MNEMONIC];
}
