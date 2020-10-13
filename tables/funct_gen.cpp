#include <iostream>
#include <unordered_map>
#include "funct_gen.hpp"

JSObject functGen()
{
    JSObject result;
    result["add"] = "100000";
    result["addu"] = "100001";
    result["and"] = "100100";
    result["jr"] = "001000";
    result["nor"] = "100111";
    result["or"] = "100101";
    result["slt"] = "101010";
    result["sltu"] = "101001";
    result["sll"] = "000000";
    result["srl"] = "000010";
    result["sub"] = "100010";
    result["subu"] = "100011";

    result["div"] = "011010";
    result["divu"] = "011011";
    result["mfhi"] = "010000";
    result["mflo"] = "010010";
    result["mult"] = "011000";
    result["multu"] = "011001";
    result["sra"] = "000011";

    result["addi"] = "001000";
    result["addiu"] = "001001";
    result["beq"] = "000100";
    result["bne"] = "000101";
    result["lbu"] = "100100";
    result["lhu"] = "100101";
    result["lw"] = "100011";
    result["sb"] = "101000";
    result["sh"] = "101001";

    return result;
}
