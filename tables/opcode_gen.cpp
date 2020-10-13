#include <iostream>
#include <unordered_map>
#include "opcode_gen.hpp"

JSObject opcodeGen()
{
    JSObject result;
    result["add"] = "000000";
    result["addu"] = "000000";
    result["and"] = "000000";
    result["jr"] = "000000";
    result["nor"] = "000000";
    result["or"] = "000000";
    result["slt"] = "000000";
    result["sltu"] = "000000";
    result["sll"] = "000000";
    result["srl"] = "000000";
    result["sub"] = "000000";
    result["subu"] = "000000";

    result["div"] = "000000";
    result["divu"] = "000000";
    result["mfhi"] = "000000";
    result["mflo"] = "000000";
    result["mult"] = "000000";
    result["multu"] = "000000";
    result["sra"] = "000000";

    result["addi"] = "001000";
    result["addiu"] = "001001";
    result["beq"] = "000100";
    result["bne"] = "000101";
    result["lbu"] = "011000";
    result["lhu"] = "011001";
    result["ll"] = "011110";
    result["lw"] = "010111";
    result["sb"] = "011100";
    result["sc"] = "100110";
    result["sh"] = "011101";
    result["lwc1"] = "011111";
    result["ldc1"] = "100011";
    result["swc1"] = "100111";

    result["j"] = "000010";
    result["jal"] = "000011";

    return result;
}
