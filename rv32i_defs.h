/**
 * Holds defs for our RiscV Implementation
 * Author: Ian McJohn
 */

#ifndef RISC_EMU_RV32I_DEFS_H
#define RISC_EMU_RV32I_DEFS_H

// 32-bit words are 4 bytes
#include <cstdint>
#include <map>
#include "utils.h"

#define WORDS_TO_BYTES(x) x*4
#define BYTES_TO_WORDS(x) x/4
typedef uint32_t word;

// processor details
#define REG_COUNT 32

// heavy struct that can be populated with every possible instruction field
struct rv32i_inst{
    word funct7, rs2, rs1, funct3, rd, opcode;
    word imm_i, imm_s, imm_b, imm_u, imm_j;
};
typedef struct rv32i_inst inst;

// all instructions in this instruction set
enum rv32i_instruction_set{
    LUI,   // opcode: 0b0110111
    JAL,   // opcode: 0b1101111
    JALR,  // opcode: 0b1100111
    BRANCH_OPCODES, // Special value for below ops
    BEQ,   // opcode: 0b1100011
    BNE,   // opcode: 0b1100011
    BLT,   // opcode: 0b1100011
    BGE,   // opcode: 0b1100011
    BLTU,  // opcode: 0b1100011
    BGEU,  // opcode: 0b1100011
    // end of special value section
    LW,    // opcode: 0b0000011
    SW,    // opcode: 0b0100011
    ALU_IMM_OPCODES, // Special value for below ops
    ADDI,  // opcode: 0b0010011
    SLTI,  // opcode: 0b0010011
    SLTIU, // opcode: 0b0010011
    XORI,  // opcode: 0b0010011
    ORI,   // opcode: 0b0010011
    ANDI,  // opcode: 0b0010011
    SLLI,  // opcode: 0b0010011
    SRLI,  // opcode: 0b0010011
    SRAI,  // opcode: 0b0010011
    // end of special value sections
    ALU_OPCODES, // Special value for below ops
    ADD,   // opcode: 0b0110011
    SUB,   // opcode: 0b0110011
    SLL,   // opcode: 0b0110011
    SLT,   // opcode: 0b0110011
    SLTU,  // opcode: 0b0110011
    XOR,   // opcode: 0b0110011
    SRL,   // opcode: 0b0110011
    SRA,   // opcode: 0b0110011
    OR,    // opcode: 0b0110011
    AND    // opcode: 0b0110011
};
typedef enum rv32i_instruction_set instruction_set;

// opcode mapping
static const std::map<word, rv32i_instruction_set> opcode_map={
        {0b0110111, LUI},
        {0b1101111, JAL},
        {0b1100111, JALR},
        {0b1100011, BRANCH_OPCODES},
        {0b0000011, LW},
        {0b0100011, SW},
        {0b0010011, ALU_IMM_OPCODES},
        {0b0110011, ALU_OPCODES}
};
#endif //RISC_EMU_RV32I_DEFS_H
