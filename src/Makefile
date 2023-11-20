main:
	g++ -c main.cpp Graph.cpp GraphVisualizer.cpp Vertex.cpp Edge.cpp InputParser.cpp Solver.cpp -I$(CURDIR)/SFML/sfml/include
	g++ Solver.o -o Solver InputParser.o -o InputParser Edge.o -o Edge Vertex.o -o Vertex GraphVisualizer.o -o GraphVisualizer Graph.o -o Graph main.o -o main -L$(CURDIR)/SFML/sfml/lib -lsfml-graphics -lsfml-window -lsfml-system


clean:
	rm -f main main.o GraphVisualizer GraphVisualizer.o Graph Graph.o Vertex Vertex.o Edge Edge.o InputParser InputParser.o Solver Solver.o

all:
	make clean
	make main



