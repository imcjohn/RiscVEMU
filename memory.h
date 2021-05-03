//
// Created by Ian on 4/29/2021.
//
#ifndef RISC_EMU_MEMORY_H
#define RISC_EMU_MEMORY_H
#include <cstdint>
#include <string>
#include <algorithm>    // std::min
#include <iostream>
#include <fstream>
#include <iomanip>      // std::setw
#include "utils.h"
#include "riscv_defs.h"

typedef uint32_t word;

class SysMemory {
    SysMemory(uint32_t size);
    ~SysMemory();
    // cpu calls
    word get(uint32_t addr);
    void set(uint32_t addr, word val);
    // emu calls
    bool load_vmh(std::string filename);
    bool dump_vmh(std::string filename);
    void resize(uint32_t size);
    // instance vars
    uint32_t heap_size;
    uint32_t highest_addr; // highest addr written to, for vmh dump
    word *heap;
};


#endif //RISC_EMU_MEMORY_H
