#include <iostream>
#include <vector>

#include "format_type.hpp"
#include "../tables/addr_gen.hpp"

using namespace std;

JSObject addr_table = addrGen();

JSObject addr_reverseGen()
{
    JSObject reverseMap;
    for (auto it = addr_table.begin(); it != addr_table.end(); it++)
        reverseMap[it->second] = it->first;
    return reverseMap;
}

JSObject addr_reverse_table = addr_reverseGen();

string addr_of(string MNEMONIC)
{
    return addr_table[MNEMONIC];
}

string addr_reverse_of(string MNEMONIC)
{
    return addr_reverse_table[MNEMONIC];
}
