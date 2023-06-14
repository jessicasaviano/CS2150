#Jessica Saviano
#jrs5xrw
#3/15/22
#worPuzzle.cpp

#Makefile


CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2 # Enable all warnings
DEBUG=-g

OBJECTS = wordPuzzle.cpp hashTable.cpp timer.cpp

Tester:  $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS)


wordPuzzle.o: hashTable.cpp hashTable.h
hashTable.o: hashTable.h hashTable.cpp
timer.o: timer.h timer.cpp


.PHONY: clean
clean:
	-rm -f *.o Tester
