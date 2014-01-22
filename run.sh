#ddd --debugger gdb -x "gdb.cmds" --args qemu-system-arm -M mini2440 -nographic -pflash uart.bin -serial stdio -mtdblock mini2440_nand128.bin
#make clean
#make
echo $1
qemu-system-arm -M mini2440 -nographic -pflash uart.bin -serial $1 -mtdblock mini2440_nand128.bin
