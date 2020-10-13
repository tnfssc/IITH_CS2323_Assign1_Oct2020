#include <iostream>
#include <vector>

#include "funct_type.hpp"
#include "../tables/funct_gen.hpp"

using namespace std;

JSObject funct_table = functGen();

JSObject funct_reverseGen()
{
    JSObject reverseMap;
    for (auto it = funct_table.begin(); it != funct_table.end(); it++)
        reverseMap[it->second] = it->first;
    return reverseMap;
}

JSObject funct_reverse_table = funct_reverseGen();

string funct_of(string MNEMONIC)
{
    return funct_table[MNEMONIC];
}

string funct_reverse_of(string MNEMONIC)
{
    return funct_table[MNEMONIC];
}
