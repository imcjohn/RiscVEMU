//
// Created by Ian on 5/11/2021.
//

#include "riscV32I.h"

/**
 * Populate a struct with every possible field of an instruction
 * @param raw_inst
 * @return
 */
inst riscV32I::populate_inst(word raw_inst) {
    inst ei;

    // populate all possible fields
    ei.opcode = raw_inst & 0b1111111;
    ei.rd     = (raw_inst >> 7) & 0b11111;
    ei.funct3 = (raw_inst >> 12) & 0b111;
    ei.rs1    = (raw_inst >> 15) & 0b11111;
    ei.rs2    = (raw_inst >> 20) & 0b11111;
    ei.funct7 = (raw_inst >> 25) & 0b1111111;

    // simple (ish) immediate values
    ei.imm_i  = (raw_inst >> 20);
    ei.imm_i  = sign_extend(ei.imm_i, 11);
    ei.imm_s  = ((raw_inst >> 7) & 0b11111) | ((raw_inst >> 25) << 5); // written out verbosely for upper and lower bits
    ei.imm_s  = sign_extend(ei.imm_s, 11);
    ei.imm_u  = (raw_inst >> 12) << 12; // this might seem ridiculous, but it actually makes sense per spec (yeet lowest 12 bits)

    // imm-b
    // first extract components
    word b_imm_1_4  = (raw_inst >> 8)  & 0b1111;
    word b_imm_11   = (raw_inst >> 7)  & 0b1;
    word b_imm_10_5 = (raw_inst >> 25) & 0b111111;
    word b_imm_12   = (raw_inst >> 31) & 0b1;
    ei.imm_b  = (b_imm_1_4 << 1) | (b_imm_11 << 11) | (b_imm_10_5 << 5) | (b_imm_12 << 12);
    sign_extend(ei.imm_b, 12);

    // imm-j
    word j_imm_19_12 = (raw_inst >> 12) & 0b11111111;
    word j_imm_11    = (raw_inst >> 20) & 0b1;
    word j_imm_10_1  = (raw_inst >> 21) & 0b1111111111;
    word j_imm_20    = (raw_inst >> 31) & 0b1;
    ei.imm_j = (j_imm_19_12 << 12) | (j_imm_11 << 11) | (j_imm_10_1 << 1) | (j_imm_20 << 20);

    return ei;
}

/**
 * Convert opcode/other bits into the exact instruction.
 * Not how processors usually work but a fun exercise (makes it more interesting to step thru the code)
 * @param decoded_instruction opcode to extract from
 * @return enumerated instruction
 */
instruction_set riscV32I::extract_inst(inst decoded_instruction) {
    return ADD;
}
