project(risc-emu)
set(CMAKE_CXX_STANDARD 14)
file (GLOB SOURCES *.cpp)
add_executable (emu main.cpp memory.cpp utils.cpp)