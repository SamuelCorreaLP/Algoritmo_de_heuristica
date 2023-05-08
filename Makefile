CXX=g++
CXXFLAGS=-g -ggdb -O2 -Wall

TARGET=main
OBJS=main.o \
	grafo.o \
	heuristicaConstrutiva.o  

all: $(TARGET)

clean:
	rm -rf $(TARGET) $(OBJS)

install:
	cp $(TARGET) /usr/local/bin

main.o: grafo.h heuristicaConstrutiva.h
grafo.o: grafo.h aresta.h
heuristicaConstrutiva.o: heuristicaConstrutiva.h aresta.h grafo.h

$(TARGET): $(OBJS)
		   $(CXX) -o $(TARGET) $(OBJS)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c -o $@ $<
