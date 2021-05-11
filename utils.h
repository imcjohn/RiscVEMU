//
// Created by Ian on 4/29/2021.
//

#ifndef RISC_EMU_UTILS_H
#define RISC_EMU_UTILS_H
#include <cstdint>
#include <cstdlib>
#include <string>
#include <vector>

uint32_t load_hex_number(std::string text, int offset);

void split_string(std::vector<std::string> *split, std::string string);
#endif //RISC_EMU_UTILS_H
