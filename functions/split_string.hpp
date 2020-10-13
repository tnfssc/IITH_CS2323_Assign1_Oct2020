#ifndef STRING_SPLIT_HPP
#define STRING_SPLIT_HPP

#include <iostream>
#include <vector>

using namespace std;

vector<string> split_string(string str, string token);
string trim_string(string &str);
string bin2hex(const string &input);
string hex2bin(const string &input);

#endif
