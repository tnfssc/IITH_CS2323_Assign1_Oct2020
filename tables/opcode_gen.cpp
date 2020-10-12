#include<iostream>
#include<unordered_map>
#include "opcode_gen.hpp"

JSObject opcodeGen () {
    JSObject result;
    result["add"] = "000000";
    result["sub"] = "000000";
    result["mult"] = "000000";
    result["multu"] = "000000";
    result["div"] = "000000";
    result["divu"] = "000000";
    result["mfhi"] = "000000";
    result["mflo"] = "000000";
    result["lis"] = "000000";
    result["slt"] = "000000";
    result["sltu"] = "000000";
    result["jr"] = "000000";
    result["jalr"] = "000000";

    result["lw"] = "100011";
    result["sw"] = "101011";

    result["beq"] = "000100";
    result["bne"] = "000101";

    return result;
}
