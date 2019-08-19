#!/bin/bash

GEM5_DIR=/home/jzy/workspace/gem5
TOOL_DIR=/home/jzy/workspace/arm64-tools/gcc-linux-gnu/bin
GCC=$TOOL_DIR/aarch64-linux-gnu-gcc
OBJDUMP=$TOOL_DIR/aarch64-linux-gnu-objdump
#GCC=gcc
#OBJDUMP=objdump

test_name=$1
[ -f $test_name.c ] || exit

#$GCC -Wall -g -c -o $test_name.o $test_name.c
$GCC -static -Wall -g -O0 -o $test_name $test_name.c
$OBJDUMP -D $test_name > $test_name-dump.S
ls -l $test_name*
grep "<main>" -rwn $test_name-dump.S -A 50
cp $test_name $GEM5_DIR/tests/test-progs/$test_name/bin/arm64/linux/
ls -lt $test_name $GEM5_DIR/tests/test-progs/$test_name/bin/arm64/linux/
