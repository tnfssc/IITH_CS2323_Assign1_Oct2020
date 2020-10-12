#include <iostream>
#include <vector>

#include "opcode_type.hpp"
#include "../tables/opcode_gen.hpp"

using namespace std;

string opcode_of(string MNEMONIC)
{
    JSObject table = opcodeGen();
    return table[MNEMONIC];
}
