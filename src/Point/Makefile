CC= gcc
CFLAGS=  -Wall -g #-std=c11
LIB= ../../lib
LDFLAGS= -lm -lpoint
INC= ../../include
EXEC= test.exe
SRC= test.c  # exemple de code utilisant entrees

all : $(EXEC)

test.exe : test.c
	$(CC) $(CFLAGS) test.c  -o  test.exe  -I $(INC) -L $(LIB) $(LDFLAGS)

clean:
	rm *.exe *.o