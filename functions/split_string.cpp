#include <iostream>
#include <vector>

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