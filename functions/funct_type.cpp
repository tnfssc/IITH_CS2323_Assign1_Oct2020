#include <iostream>
#include <vector>

#include "funct_type.hpp"
#include "../tables/funct_gen.hpp"

using namespace std;

JSObject funct_table = functGen();

string funct_of(string MNEMONIC)
{
    return funct_table[MNEMONIC];
}
