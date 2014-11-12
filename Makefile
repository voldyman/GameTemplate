BIN = sfml-app

CC?=clang

SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system
OTHER_LIBS = -lstdc++
OTHER_FLAGS = --std=c++11 -Wc++11-extensions
FLAGS = $(SFML_LIBS) $(OTHER_LIBS) $(OTHER_FLAGS)

OBJ = src/main.o

all: $(OBJ)
	$(CC) -o $(BIN) $(FLAGS) $^

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean run

run: all
	./$(BIN)

clean:
	rm $(OBJ)
	rm $(BIN)

