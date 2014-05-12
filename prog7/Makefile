dtest: HashTable.o DateTest.o
	g++ -o dtest HashTable.o DateTest.o

HashTable.o: HashTable.cpp
	g++ -c HashTable.cpp

DateTest.o: DateTest.cpp
	g++ -c DateTest.cpp

clean:
	rm dtest *.o