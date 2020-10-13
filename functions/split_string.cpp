#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

vector<string> split_string(string str, string token)
{
    vector<string> result;
    while (str.size())
    {
        int index = str.find(token);
        if (index != string::npos)
        {
            result.push_back(str.substr(0, index));
            str = str.substr(index + token.size());
            if (str.size() == 0)
                result.push_back(str);
        }
        else
        {
            result.push_back(str);
            str = "";
        }
    }
    return result;
}

string trim_string(string &str)
{
    str.erase(0, str.find_first_not_of(' '));
    str.erase(str.find_last_not_of(' ') + 1);
    return str;
}

string hex2bin(const string &s)
{
    string out;
    for (auto i : s)
    {
        uint8_t n;
        if (i <= '9' && i >= '0')
            n = i - '0';
        else
            n = 10 + i - 'A';
        for (int8_t j = 3; j >= 0; --j)
            out.push_back((n & (1 << j)) ? '1' : '0');
    }

    return out;
}

string bin2hex(const string &s)
{
    string out;
    for (int i = 0; i < s.size(); i += 4)
    {
        int8_t n = 0;
        for (int j = i; j < i + 4; ++j)
        {
            n <<= 1;
            if (s[j] == '1')
                n |= 1;
        }

        if (n <= 9)
            out.push_back('0' + n);
        else
            out.push_back('A' + n - 10);
    }

    return out;
}

#define ull unsigned long long int

int decimalToBinary(int N)
{
    ull B_Number = 0;
    int cnt = 0;
    while (N != 0)
    {
        int rem = N % 2;
        ull c = pow(10, cnt);
        B_Number += rem * c;
        N /= 2;
        cnt++;
    }

    return B_Number;
}

string binaryToDecimalStrings(string bin)
{
    const string s = bin;
    unsigned long long value = stoull(s, 0, 2);
    string number;
    stringstream strstream;
    strstream << value;
    strstream >> number;
    return number;
}
