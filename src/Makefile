main:
	g++ -c main.cpp Graph.cpp GraphVisualizer.cpp Vertex.cpp Edge.cpp -I$(CURDIR)/SFML/sfml/include
	g++ Edge.o -o Edge Vertex.o -o Vertex GraphVisualizer.o -o GraphVisualizer Graph.o -o Graph main.o -o main -L$(CURDIR)/SFML/sfml/lib -lsfml-graphics -lsfml-window -lsfml-system


clean:
	rm -f main main.o GraphVisualizer GraphVisualizer.o Graph Graph.o Vertex Vertex.o Edge Edge.o

all:
	make clean
	make main



