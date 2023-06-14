#Makefile


CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2 # Enable all warnings
DEBUG=-g

OBJECTS =BinarySearchTree.cpp BinaryNode.cpp BSTPathTest.cpp

Tester:  $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS)


BinarySearchTree.o: BinarySearchTree.cpp BinarySearchTree.h
TreeCalcTest.o: BSTPathTest.cpp
TreeNode.o: BinaryNode.cpp BinaryNode.h

.PHONY: clean
clean:
	-rm -f *.o Tester
