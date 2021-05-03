//
// Created by Ian on 4/29/2021.
//
#include "utils.h"

/**
 * Load a (lowercase) hexadecimal number from a string
 * @param text string to load from
 * @param offset position at which the number starts
 * @return number as 32-bit word
 */
uint32_t load_hex_number(std::string text, int offset){
    uint32_t ret;
    text.erase(0, offset);
    const char *s_val = text.c_str();
    scanf("%x", &ret);
    return ret;
}