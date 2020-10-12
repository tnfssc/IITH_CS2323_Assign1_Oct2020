#include <iostream>
#include <vector>

#include "funct_type.hpp"
#include "../tables/funct_gen.hpp"

using namespace std;

string funct_of(string MNEMONIC)
{
    JSObject table = functGen();
    return table[MNEMONIC];
}
