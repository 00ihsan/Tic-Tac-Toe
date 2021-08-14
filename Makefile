CC=gcc

EXECUTABLE_NAME = Tic-Tac-Toe

NAME = $(EXECUTABLE_NAME)

$(EXECUTABLE_NAME): src/compilationfiles/$(NAME).o src/compilationfiles/Game.o
	$(CC) src/compilationfiles/$(NAME).o src/compilationfiles/Game.o src/Player.h
	mv a.out builds/$(EXECUTABLE_NAME)
	rm -f src/Game.h.gch
	rm -f src/Player.h.gch
	
src/compilationfiles/$(NAME).o: src/compilationfiles/Game.o src/$(NAME).c
	$(CC) src/$(NAME).c src/compilationfiles/Game.o -c
	mv $(NAME).o src/compilationfiles/$(NAME).o

src/compilationfiles/Game.o: src/Game.c src/Game.h src/Player.h
	$(CC) -c src/Game.c src/Game.h src/Player.h
	mv Game.o src/compilationfiles/Game.o
	
run: $(EXECUTABLE_NAME)
	make
	reset
	./builds/$(EXECUTABLE_NAME)

clean:
	rm -f src/compilationfiles/Game.o
	rm -f src/compilationfiles/$(NAME).o
	rm -f src/Player.h.gch
	rm -f src/Game.h.gch
