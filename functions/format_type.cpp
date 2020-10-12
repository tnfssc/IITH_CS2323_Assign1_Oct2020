#include <iostream>
#include <vector>

#include "format_type.hpp"
#include "../tables/format_gen.hpp"

using namespace std;

string format_of(string MNEMONIC)
{
    JSObject table = formatGen();
    return table[MNEMONIC];
}
