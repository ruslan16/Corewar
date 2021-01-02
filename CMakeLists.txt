cmake_minimum_required(VERSION 3.17)
project(Corewar C)

set(CMAKE_C_STANDARD 11)

include_directories(includes)
include_directories(includes/asm)
include_directories(includes/system)
include_directories(libft/includes)

add_executable(Corewar
        asm/add.c
        asm/dlc_read.c
        asm/free.c
        asm/get.c
        asm/get_bytes.c
        asm/get_type_arg.c
        asm/init.c
        asm/main.c
        asm/op.c
        asm/open_file.c
        asm/pars_line.c
        asm/read_file.c
        asm/translate.c
        asm/trash_fun.c
        asm/bonus.c
        includes/asm/asm.h
        includes/system/op.h
)
find_library(FT ft libft)
target_link_libraries(Corewar LINK_PUBLIC ${FT})