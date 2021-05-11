/**
 * Executable stub for RiscVEMU
 *
 * Author: Ian McJohn
 */

#include <iostream>
#include "cli.h"

int main() {
    Cli *c = new Cli();
    while(c->run());
    return 0;
}