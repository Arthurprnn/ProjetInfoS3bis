#Entrees
CC= gcc
CFLAGS=  -Wall -g #-std=c11
LIB= ../../lib
LDFLAGS= -lm -lpoint -lparametres -lentrees
INC= ../../include
EXEC= test.exe
SRC= test.c
OBJ= $(SRC:.c=.o)

all : $(EXEC)

$(EXEC): $(SRC)
	$(CC) $< -o $@ $(CFLAGS) $(LDFLAGS) -I $(INC) -L $(LIB)

clean:
	rm *.exe