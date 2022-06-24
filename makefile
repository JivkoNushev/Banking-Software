FILES = main.o menu.o
CFLAGS = -Wall -pedantic -std=c11

all: ${FILES}
	g++ -Wall ${FILES} -o main.out

%.o: %.c
	g++ ${CFLAGS} -c $< -o $@

clean:
	rm *.o *.out

open:
	code main.cpp menu.cpp menu.h bill.cpp bill.h transactions.cpp transactions.h user.cpp user.h makefile

OPEN:
	gedit main.cpp

