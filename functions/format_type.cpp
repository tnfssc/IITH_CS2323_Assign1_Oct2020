#include <iostream>
#include <vector>

#include "format_type.hpp"
#include "../tables/format_gen.hpp"

using namespace std;

JSObject format_table = formatGen();

string format_of(string MNEMONIC)
{
    return format_table[MNEMONIC];
}
