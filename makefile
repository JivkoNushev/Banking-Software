FILES = main.o menu.o user.o bill.o transaction.o hash.o 
CFLAGS = -Wall -pedantic

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

run:
	./main.out

trash:
	rm user_database.txt
	touch user_database.txt
	rm bill_database.txt
	touch bill_database.txt

new:
	make trash
	make all
	make run
