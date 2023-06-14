#Makefile


CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2 # Enable all warnings
DEBUG=-g

OBJECTS = AVLTree.cpp AVLNode.cpp AVLPathTest.cpp

Tester:  $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS)


AVLTree.o: AVLTree.cpp AVLTree.h
AVLPathTest.o: AVLPathTest.cpp
AVLNode.o: AVLNode.cpp AVLNode.h

.PHONY: clean
clean:
	-rm -f *.o Tester
