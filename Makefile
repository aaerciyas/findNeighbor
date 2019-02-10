compile:
	g++ findNeighbor.cpp -o findNeighbor
debug:
	g++ findNeighbor.cpp -o findNeighbor -DDEBUG
clean:
	rm findNeighbor