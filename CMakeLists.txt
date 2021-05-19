project(risc-emu)
set(CMAKE_CXX_STANDARD 14)
file (GLOB SOURCES *.cpp)
add_executable (emu main.cpp memory.cpp utils.cpp cli.cpp cli.h riscV32I.cpp riscV32I.h)