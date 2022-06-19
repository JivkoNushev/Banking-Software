FILES = main.o dataTypes.h menu.o
CFLAGS = -Wall -pedantic -std=c11

all: ${FILES}
	g++ -Wall ${FILES} -o main.out

%.o: %.c
	g++ ${CFLAGS} -c $< -o $@

clean:
	rm *.o *.out

open:
	code main.c

OPEN:
	gedit main.c

