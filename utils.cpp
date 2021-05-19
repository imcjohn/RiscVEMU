//
// Created by Ian on 4/29/2021.
//
#include <sstream>
#include "utils.h"

/**
 * Load a (lowercase) hexadecimal number from a string
 * @param text string to load from
 * @param offset position at which the number starts
 * @return number as 32-bit word
 */
uint32_t load_hex_number(std::string text, int offset){
    uint32_t ret;
    const char *s_val = text.c_str() + offset;
    sscanf(s_val, "%x", &ret);
    return ret;
}

/**
 * Split a string by spaces
 * @param split output vector for split string (cleared first)
 * @param string string to split
 */
void split_string(std::vector<std::string> *split, std::string str) {
    using namespace std;
    split->clear();
    stringstream ss(str);
    string word;
    while (ss >> word)
        split->push_back(word);
}

/**
 * Sign-extend number numb starting at bit idx
 * @param numb number to sign extend
 * @param idx bit to sign-extend from (in [0,31])
 * @return sign-extended numb
 */
uint32_t sign_extend(uint32_t numb, uint32_t idx) {
    char bit = (numb >> idx) & 1;
    uint32_t mask = 0xFFFFFFFF;
    mask = (mask >> idx);
    mask = (mask << idx);
    return (bit)? (numb | mask) : numb;
}
