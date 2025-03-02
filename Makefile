CC = gcc
CFLAGS = -Wall -g
SRC = main.c fsm.c
OBJ = $(SRC:.c=.o)
EXE = main.exe

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXE)

.PHONY: all clean
