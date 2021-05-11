//
// Created by Ian on 5/4/2021.
//

#ifndef RISC_EMU_CLI_H
#define RISC_EMU_CLI_H

#include "riscv_defs.h"
#include "memory.h"

class Cli {
public:
    Cli();
    ~Cli();
    bool run();
private:
    int inst_mem_sz;
    int data_mem_sz;
    SysMemory *inst_mem;
    SysMemory *data_mem;
    void decode_cmd(std::string &cmd);
};


#endif //RISC_EMU_CLI_H
