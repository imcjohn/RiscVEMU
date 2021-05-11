//
// Created by Ian on 4/29/2021.
//

#include "memory.h"

/**
 * Initialize a SysMemory object of size words
 * @param size # of words big to make the memory
 */
SysMemory::SysMemory(uint32_t size) {
    heap = new word[size];
    heap_size = size;
    highest_addr = 0;
}

SysMemory::~SysMemory() {
    delete[] heap;
}

/**
 * Return word at memory address addr
 * @param addr index into heap
 * @return word at that memory address
 */
word SysMemory::get(uint32_t addr) {
    if (addr < WORDS_TO_BYTES(heap_size)) return heap[BYTES_TO_WORDS(addr)];
}

/**
 * Set word at memory address addr equal to val
 * @param addr address to index
 * @param val value to assign
 */
void SysMemory::set(uint32_t addr, word val) {
    if (addr < WORDS_TO_BYTES(heap_size)){
        heap[BYTES_TO_WORDS(addr)] = val;
        highest_addr = std::max(highest_addr, addr);
    }
}

/**
 * Populate memory from VMH, failing if memory is too small
 * @param filename vmh file to load
 * @return true if successful, otherwise false
 */
bool SysMemory::load_vmh(std::string filename) {
    std::string line;
    std::ifstream handle(filename);
    if (!handle.is_open()) return false;
    int pos = 0;
    while (getline(handle, line)){
        if (line.empty()) continue;
        if (line[0] == '@'){
            // positioning line, adjust pos accordingly (addrs in VMH are word addresses)
            pos = WORDS_TO_BYTES(load_hex_number(line, 1));
        }
        else{
            set(pos, load_hex_number(line, 0));
            pos += 4; // increase by a word
        }
    }
    return true;
}

/**
 * Write memory to VMH file
 * @param filename VMH file to output
 * @return true if successful, otherwise false
 */
bool SysMemory::dump_vmh(std::string filename) {
    std::ofstream outfile(filename);
    if (!outfile.is_open()) return false;
    outfile << "@0" << std::endl;
    outfile << std::hex << std::setfill('0') << std::setw(8);
    int last_addr = 0;
    for (int i = 0; i < BYTES_TO_WORDS(highest_addr); ++i){
        outfile << heap[i] << "\n";
        last_addr += 4;
    }
    outfile << "@" << BYTES_TO_WORDS(last_addr) << std::endl;
    outfile.close();
    return true;
}

/**
 * Resize memory to size words
 * @param size new memory size, in words
 */
void SysMemory::resize(uint32_t size) {
    word *new_heap = new word[size];
    for (int i = 0; i < std::min(size, heap_size); ++i){
        new_heap[i] = heap[i];
    }
    delete[] heap;
    heap = new_heap;
    heap_size = size;
    highest_addr = std::min(highest_addr, WORDS_TO_BYTES(heap_size-1));
}