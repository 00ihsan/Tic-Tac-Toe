CC=gcc
EXECUTABLE_NAME = Tic_Tac_Toe
NAME = Tic-Tac-Toe

$(EXECUTABLE_NAME): $(NAME).o Game.o
	$(CC) $(NAME).o Game.o Player.h -o $(EXECUTABLE_NAME)

$(NAME).o: Game.o
	$(CC) $(NAME).c Game.h -c

Game.o: Game.c Game.h Player.h
	$(CC) -c Game.c Game.h Player.h

run: $(EXECUTABLE_NAME)
	./$(EXECUTABLE_NAME)