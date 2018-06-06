# Corewar

Compilation: make

This project is made of 2 binaries: asm and corewar

Core War (or Core Wars) is a programming game where assembly programs try to destroy each other in the memory of a simulated computer. The programs (or warriors) are written in a special language called Redcode, and run by a program called MARS (Memory Array Redcode Simulator). from http://vyznev.net/corewar/guide.html

- With asm you can create a program
- Corewar is basically our implementation of MARS, you can launch your champion with that.

## ASM

USAGE
  - ./asm file_name[.s]

DESCRIPTION
  - file_name file in assembly language to be converted into file_name.cor, an executable in the Virtual Machine.

## COREWAR

USAGE
  - ./corewar [-dump nbr_cycle] [[-n prog_number] [-a load_address] prog_name] ...
     
DESCRIPTION
  - -dump nbr_cycle: dumps the memory after the nbr_cycle execution (if the round isn’t already over) with the following format: 32 bytes/line in
hexadecimal (A0BCDEFE1DD3...)
  - -n prog_number: sets the next program’s number. By default, the first free number
in the parameter order
  - -a load_address: sets the next program’s loading address. When no address is specified, optimize the addresses so that the processes are as faraway from each other as possible. The addresses are MEM_SIZE modulo

Made with Alexandre Fourcat https://github.com/Afourcat, nwmqpa https://github.com/nwmqpa and Quentin Dieppe https://github.com/qdieppeEpitech
