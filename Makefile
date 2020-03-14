GCC=gcc
#CFLAGS=-c -g
CFLAGS=-m32 -O0 -g3 -Wall -ansi 
LFLAGS=
EXE=program

all: ${EXE}.o
	${GCC} ${LFLAGS} ${EXE}.o -o ${EXE}

${EXE}.o: ${EXE}.c
	${GCC} ${CFLAGS} ${EXE}.c

clean:
	rm -rf *.o
	rm -rf ${EXE}

#gcc -m32 -Wall -ansi -O0 -g3 -std=c17 program.c -o program