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
uint32_t sign_extend(uint32_t numb, uint32_t idx);

void split_string(std::vector<std::string> *split, std::string string);

#define make_lower(s) for (char & i : s) i = std::tolower(i);
#endif //RISC_EMU_UTILS_H
