/**
 * Executable stub for RiscVEMU
 *
 * Author: Ian McJohn
 */

#include <iostream>
#include "cli.h"

int main() {

    Cli *cli = new Cli();
    while(cli->run());
    return 0;
}