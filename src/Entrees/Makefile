CC= gcc
CFLAGS=  -Wall -g #-std=c11
LIB= ../../lib
LDFLAGS= -lm -lSystem
INC= ../../include
EXEC= test.exe
SRC= entrees.c
OBJ= $(SRC:.c=.o)

all : $(EXEC)

test.exe : test.c $(LIB)/libentrees.a entrees.o
	$(CC) $(CFLAGS) test.c $(OBJ) -o test.exe  -I $(INC)

entrees.o : entrees.c 
	$(CC) $(CFLAGS)  -c entrees.c -I $(INC)

$(LIB)/libentrees.a : $(OBJ) $(INC)/entrees.h
	ar rcs $(LIB)/libentrees.a $(OBJ)
	ranlib $(LIB)/libentrees.a

clean:
	rm $(LIB)/libentrees.a *.exe *.o