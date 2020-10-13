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

    return result;
}
