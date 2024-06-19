CC = g++
SRC = main.cpp card.cpp cardManager.cpp
OBJ = $(SRC:.c=.o)
EXEC = main

$(EXEC): $(OBJ)
	$(CC) -std=c++11 -o $@ $^

%.o: %.c %.h
	$(CC) -c $<

clean:
	del $(EXEC).exe