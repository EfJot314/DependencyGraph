main:
	g++ -c main.cpp Graph.cpp GraphVisualizer.cpp -I$(CURDIR)/SFML/sfml/include
	g++ GraphVisualizer.o -o GraphVisualizer Graph.o -o Graph main.o -o main -L$(CURDIR)/SFML/sfml/lib -lsfml-graphics -lsfml-window -lsfml-system


clean:
	rm -f main main.o GraphVisualizer GraphVisualizer.o Graph Graph.o

all:
	make clean
	make main



