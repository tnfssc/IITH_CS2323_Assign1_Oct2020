#include <iostream>
#include <vector>

#include "format_type.hpp"
#include "../tables/format_gen.hpp"

using namespace std;

JSObject format_table = formatGen();

JSObject format_reverseGen()
{
    JSObject reverseMap;
    for (auto it = format_table.begin(); it != format_table.end(); it++)
        reverseMap[it->second] = it->first;
    return reverseMap;
}

JSObject funct_reverse_table = format_reverseGen();

string format_of(string MNEMONIC)
{
    return format_table[MNEMONIC];
}

string format_reverse_of(string MNEMONIC)
{
    return format_table[MNEMONIC];
}
