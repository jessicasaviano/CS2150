#Makefile


CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2 # Enable all warnings
DEBUG=-g

OBJECTS = wordPuzzle.cpp hashTable.cpp 

Tester:  $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS)


wordPuzzle.o: hashTable.cpp hashTable.h
hashTable.o: hashTable.h hashTable.cpp


.PHONY: clean
clean:
	-rm -f *.o Tester
