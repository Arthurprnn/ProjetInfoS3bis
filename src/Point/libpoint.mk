CC=gcc
CFLAGS=-Wall -g
LIB=../../lib
INC=../../include
EXEC=test.exe
SRC=test.c
OBJ=$(SRC:.c=.o)
all:$(EXEC)
$(EXEC): $(LIB)/libpoint.a
	$(CC) $(CFLAGS) test.c -o test.exe -I $(INC)

clean:
	rm *.exe *.o