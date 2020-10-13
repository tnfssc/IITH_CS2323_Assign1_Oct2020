#include <iostream>
#include <unordered_map>
#include "format_gen.hpp"

JSObject formatGen()
{
    JSObject result;
    result["add"] = "R";
    result["addu"] = "R";
    result["and"] = "R";
    result["jr"] = "R";
    result["nor"] = "R";
    result["or"] = "R";
    result["slt"] = "R";
    result["sltu"] = "R";
    result["sll"] = "R";
    result["srl"] = "R";
    result["sub"] = "R";
    result["subu"] = "R";

    result["div"] = "R";
    result["divu"] = "R";
    result["mfhi"] = "R";
    result["mflo"] = "R";
    result["mult"] = "R";
    result["multu"] = "R";
    result["sra"] = "R";

    result["addi"] = "I";
    result["addiu"] = "I";
    result["beq"] = "I";
    result["bne"] = "I";
    result["lbu"] = "I";
    result["lhu"] = "I";
    result["lw"] = "I";
    result["sb"] = "I";
    result["sh"] = "I";

    result["j"] = "J";
    result["jal"] = "J";

    result["000000"] = "R";
    result["001000"] = "I";
    result["001001"] = "I";
    result["000100"] = "I";
    result["000101"] = "I";
    result["011000"] = "I";
    result["011001"] = "I";
    result["010111"] = "I";
    result["011100"] = "I";
    result["011101"] = "I";
    result["000010"] = "J";
    result["000011"] = "J";

    return result;
}
