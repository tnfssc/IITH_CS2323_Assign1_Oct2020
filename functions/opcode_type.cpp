#include <iostream>
#include <vector>
#include <sstream>

#include "opcode_type.hpp"
#include "../tables/opcode_gen.hpp"

#include "split_string.hpp"

using namespace std;

string opcode_of(string prog_line)
{
    vector<string> arr = split_string(prog_line, " ");
    for (int i = 0; i < 4; i++)
    {
        cout << arr[i] << endl;
    }
    return prog_line;
}
