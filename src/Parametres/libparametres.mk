CC= gcc
CFLAGS=  -Wall -g #-std=c11
LIB= ../../lib
LDFLAGS= -lm
INC= ../../include
EXEC= libparametres.a
SRC= parametres.c
OBJ= $(SRC:.c=.o)

all : $(EXEC)

parametres.o : parametres.c 
	$(CC) $(CFLAGS)  -c parametres.c -I $(INC)

$(EXEC) : $(OBJ) $(INC)/parametres.h
	ar rcs $(LIB)/libparametres.a $(OBJ)
	ranlib $(LIB)/libparametres.a

clean:
	rm $(LIB)/libparametres.a parametres.o