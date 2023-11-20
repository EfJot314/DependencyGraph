main:
	g++ -c main.cpp Game.cpp Planet.cpp GameEngine.cpp -I$(CURDIR)/SFML/sfml/include
	g++ Planet.o -o Planet GameEngine.o -o GameEngine Game.o -o Game main.o -o main -L$(CURDIR)/SFML/sfml/lib -lsfml-graphics -lsfml-window -lsfml-system


clean:
	rm -f main main.o Vector2d Vector2d.o Planet Planet.o Game Game.o GameEngine GameEngine.o

all:
	make clean
	make main



