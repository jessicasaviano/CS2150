#Makefile


CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2 # Enable all warnings
DEBUG=-g

OBJECTS = TreeCalcTest.cpp TreeCalc.cpp TreeNode.cpp

Tester:  $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS)


TreeCalc.o: TreeCalc.cpp TreeCalc.h
TreeCalcTest.o: TreeCalcTest.cpp
TreeNode.o: TreeNode.cpp TreeNode.h

.PHONY: clean
clean:
	-rm -f *.o Tester
