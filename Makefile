GCC=gcc
CFLAGS=-c -g
LFLAGS=
EXE=program

all: ${EXE}.o
	${GCC} ${LFLAGS} ${EXE}.o -o ${EXE}

${EXE}.o: ${EXE}.c
	${GCC} ${CFLAGS} ${EXE}.c

clean:
	rm -rf *.o
	rm -rf ${EXE}