//
// Created by Ian on 5/11/2021.
//

#ifndef RISC_EMU_RISCV32I_H
#define RISC_EMU_RISCV32I_H

#include "rv32i_defs.h"

class riscV32I {
private:
    inst populate_inst(word raw_inst);
    instruction_set extract_inst(inst decoded_instruction);
    word reg_file[REG_COUNT];
};


#endif //RISC_EMU_RISCV32I_H
