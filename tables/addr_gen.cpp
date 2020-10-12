#include <iostream>
#include <unordered_map>
#include "addr_gen.hpp"

JSObject addrGen()
{
    JSObject result;
    result["zero"] = "00000";
    result["at"] = "00001";
    result["v0"] = "00010";
    result["v1"] = "00011";
    result["a0"] = "00100";
    result["a1"] = "00101";
    result["a2"] = "00110";
    result["a3"] = "00111";
    result["t0"] = "01000";
    result["t1"] = "01001";
    result["t2"] = "01010";
    result["t3"] = "01011";
    result["t4"] = "01100";
    result["t5"] = "01101";
    result["t6"] = "01110";
    result["t7"] = "01111";
    result["s0"] = "10000";
    result["s1"] = "10001";
    result["s2"] = "10010";
    result["s3"] = "10011";
    result["s4"] = "10100";
    result["s5"] = "10101";
    result["s6"] = "10110";
    result["s7"] = "10111";
    result["t8"] = "11000";
    result["t9"] = "11001";
    result["k0"] = "11010";
    result["k1"] = "11011";
    result["gp"] = "11100";
    result["sp"] = "11101";
    result["fp"] = "11110";
    result["ra"] = "11111";

    return result;
}
