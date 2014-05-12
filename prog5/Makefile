PrefixFinder: PrefixFinder.o WordManager.o Node.o STLMap.h AVLMap.h
	g++ -o PrefixFinder PrefixFinder.o WordManager.o Node.o

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

WordManager.o: WordManager.h Node.h STLMap.h AVLMap.h
	g++ -c WordManager.cpp

PrefixFinder.o: PrefixFinder.cpp Node.h
	g++ -c PrefixFinder.cpp

clean:
	rm PrefixFinder *.o
