CC= gcc
CFLAGS=  -Wall -g #-std=c11
LIB= ../../lib
LDFLAGS= -lm -lpoint -lparametres
INC= ../../include
EXEC= libentrees.a
SRC= entrees.c
OBJ= $(SRC:.c=.o)

all : $(EXEC)

entrees.o : entrees.c 
	$(CC) $(CFLAGS)  -c entrees.c $(LDFLAGS) -I $(INC) -L $(LIB)

$(EXEC) : $(OBJ) $(INC)/entrees.h
	ar rcs $(LIB)/libentrees.a $(OBJ)
	ranlib $(LIB)/libentrees.a

clean:
	rm $(LIB)/libentrees.a entrees.o