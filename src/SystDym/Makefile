CC= gcc
CFLAGS=  -Wall -g #-std=c11
LIB= ../../lib
LDFLAGS= -lm -lpoint -lparametres -lfichier -lentrees
INC= ../../include
EXEC= main.exe
SRC= main.c lorentz.c rossler.c 
OBJ= $(SRC:.c=.o)

all : $(EXEC)

#lorentz.o : lorentz.c 
#	$(CC) $(CFLAGS) -o lorentz.o -c lorentz.c -I $(INC) -L $(LIB)
#
#rossler.o : rossler.c 
#	$(CC) $(CFLAGS) -o rossler.o -c rossler.c -I $(INC) -L $(LIB) 
#
#$(EXEC): lorentz.o rossler.o
#	$(CC) $< -o $@ $(CFLAGS) $(LDFLAGS) -I $(INC) -L $(LIB)

$(EXEC): $(OBJ)
	@$(CC) -o $@ $^ $(LDFLAGS) $(CFLAGS) -I $(INC) -L $(LIB)

%.o: %.c 
	@$(CC) -o $@ -c $< $(CFLAGS) -I $(INC) -L $(LIB)

clean:
	rm *.exe *.o