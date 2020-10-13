#include <iostream>
#include <vector>

#include "format_type.hpp"
#include "../tables/addr_gen.hpp"

using namespace std;

JSObject addr_table = addrGen();

string addr_of(string MNEMONIC)
{
    return addr_table[MNEMONIC];
}
