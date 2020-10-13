#include <iostream>
#include <vector>

#include "funct_type.hpp"
#include "../tables/funct_gen.hpp"

using namespace std;

JSObject funct_table = functGen();

JSObject addr_reverseGen()
{
    JSObject reverseMap;
    for (auto it = funct_table.begin(); it != funct_table.end(); it++)
        reverseMap[it->second] = it->first;
    return reverseMap;
}

JSObject funct_reverse_table = addr_reverseGen();

string funct_of(string MNEMONIC)
{
    return funct_table[MNEMONIC];
}

string funct_reverse_of(string MNEMONIC)
{
    return funct_table[MNEMONIC];
}
