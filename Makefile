#!/usr/bin/env make
CC= gcc
CWARN= -Wall -pedantic
CSTD= -std=c99
OPT= -O2
ARCH=
LIBS= -lncurses
CFLAGS= ${CWARN} ${CSTD} ${ARCH} ${OPT} ${LIBS}

ENTRY= life

all: ${ENTRY} prog
	@${TRUE}

${ENTRY}: ${ENTRY}.c
	${CC} $< -o $@ ${CFLAGS}
	
prog: prog.c
	${CC} $< -o $@ ${CFLAGS}