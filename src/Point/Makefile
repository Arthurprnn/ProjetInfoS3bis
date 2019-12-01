CC= gcc
CFLAGS=  -Wall -g #-std=c11
LIB= ../../lib
LDFLAGS= -lm -lSystem
INC= ../../include
EXEC= test.exe
SRC= point.c
OBJ= $(SRC:.c=.o)

all : $(EXEC)

test.exe : test.c $(LIB)/libpoint.a point.o
	$(CC) $(CFLAGS) test.c $(OBJ) -o test.exe  -I $(INC)

point.o : point.c 
	$(CC) $(CFLAGS)  -c point.c -I $(INC)

$(LIB)/libpoint.a : $(OBJ) $(INC)/point.h
	ar rcs $(LIB)/libpoint.a $(OBJ)
	ranlib $(LIB)/libpoint.a

clean:
	rm $(LIB)/libpoint.a *.exe *.o