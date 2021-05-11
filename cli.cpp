//
// Created by Ian on 5/4/2021.
//

#include "cli.h"

Cli::Cli() {
    inst_mem_sz = BYTES_TO_WORDS(64 * 1024); // 004 uses 64kb memories
    data_mem_sz = BYTES_TO_WORDS(64 * 1024);
    inst_mem = new SysMemory(inst_mem_sz);
    data_mem = new SysMemory(data_mem_sz);
}

Cli::~Cli() {
    delete inst_mem;
    delete data_mem;
}

/**
 * Very not-tolerant CLI to run the emulator (whitespace = bad)
 *
 * Prompt and execute a single CLI command
 * @returns false if exit command recieved, otherwise true
 */
bool Cli::run() {
    std::string line;
    std::cout << "CLI> ";
    std::getline(std::cin, line);
    // to lowercase
    for (char & i : line) i = std::tolower(i);
    if (line == "exit") return false;

    decode_cmd(line);
    return true;
}

void Cli::decode_cmd(std::string &cmd) {
    std::vector<std::string> cmd_spl;
    split_string(&cmd_spl, cmd);

    if (cmd_spl.size() >= 4 && cmd_spl[0] == "set_m"){
        bool inst = cmd_spl[1][0] == 'i';
        long addr = strtol(cmd_spl[2].c_str(), NULL, 0);
        word wd = strtol(cmd_spl[3].c_str(), NULL, 0);
        if (inst)
            inst_mem->set(addr, wd);
        else
            data_mem->set(addr, wd);
    } else if (cmd_spl.size() >= 3 && cmd_spl[0] == "get_m"){
        bool inst = cmd_spl[1][0] == 'i';
        uint32_t addr = strtol(cmd_spl[2].c_str(), NULL, 0);
        word wd = (inst)? inst_mem->get(addr) : data_mem->get(addr);
        std::cout << "0x";
        std::cout << std::hex << std::setfill('0') << std::setw(8) << wd << std::endl;
    }
}
