FILES = main.o menu.o
CFLAGS = -Wall -pedantic -std=c11

all: ${FILES}
	g++ -Wall ${FILES} -o main.out

%.o: %.c
	g++ ${CFLAGS} -c $< -o $@

clean:
	rm *.o *.out

open:
	code main.cpp menu.cpp menu.h bill.cpp bill.h transaction.cpp transaction.h user.cpp user.h hash.cpp hash.h makefile

OPEN:
	gedit main.cpp

