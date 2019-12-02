CC= gcc
CFLAGS=  -Wall -g #-std=c11
LIB= ../../lib
LDFLAGS= -lm -lSystem
INC= ../../include
EXEC= test.exe
SRC= parametres.c
OBJ= $(SRC:.c=.o)

all : $(EXEC)

test.exe : test.c $(LIB)/libparametres.a parametres.o
	$(CC) $(CFLAGS) test.c $(OBJ) -o test.exe  -I $(INC)

parametres.o : parametres.c 
	$(CC) $(CFLAGS)  -c parametres.c -I $(INC)

$(LIB)/libparametres.a : $(OBJ) $(INC)/parametres.h
	ar rcs $(LIB)/libparametres.a $(OBJ)
	ranlib $(LIB)/libparametres.a

clean:
	rm $(LIB)/libparametres.a *.exe *.o