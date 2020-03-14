#!/bin/bash
gcc -m32 -Wall -ansi -O0 -g3 -std=c17 program.c -o program
./program "U+221a"