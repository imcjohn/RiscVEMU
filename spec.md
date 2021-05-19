# RiscVEmu Spec

## Overview
RiscVEmu is an emulator designed to implement the MIT 6.004 subset of the RiscV32I
instruction set, created as an exercise in creativity (004 was one of my favorite
classes back when I took it).  

### Core Components (with feature list)
#### CLI
The CLI will implement a variety of commands in order to run the emulator.\
NOTE: All numerical arguments are in hex unless specified otherwise
##### Required commands:
* start -> start CPU (from pc=0)
* halt -> stop CPU
* status -> print CPU status (004 style)
* load_mem [I/D] (vmh file) -> load either Instruction or Data memory from vmh
* dump_mem [I/D] (vmh file) -> dump I/D memory to vmh
* set_param (param) (value) -> set config param to value
* refresh -> use params to generate new instances based on those params (Ex. memory)
* dump_params -> list all config params (see below list)
##### Addl. commands (For debugging etc)
* set_r [reg] [val] -> assign [reg] to [val]
* get_r [reg] -> read value from register
* set_m [I/D] [addr] [word] -> assign memory address [addr] to [word] (I
corresponds to inst. memory, and d to data)
* get_m [I/D] [addr] -> peek at memory address [addr]
* probably some breakpoints stuff here later on
##### Config Params

| Param Name | Param Type | Description |
|------------|------------|-------------|
| imem_size  | int        | size of instruction memory (words)|
| dmem_size  | int        | size of instruction memory (words)|

#### Processor
The processor component of this system will create a class that, provided
with instruction/data memory, can step through execution as a simulated
RISC-V processor. No translation to native assembly will be done, 
although it could be a cool add for performance reasons later on. This component
will fully encapsulate ALU/PC/Addressing logic, with only I/DMem in separate
classes

#### Memory
The memory components of this system consist of 2 instances of our Memory class,
which can load/store memory from VMH files
 