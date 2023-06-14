// Jessica Saviano jrs5xrw

#ifndef HEAPNODE_H
#define HEAPNODE_H

#include <iostream>
#include <vector>
#include <string>


using namespace std;

class heapNode {

 public:
  heapNode(char letter, int freq);
  heapNode();
  int freq1;
  char letter1;
  heapNode *rightC;
  heapNode *leftC;
  bool leaf(heapNode* r);

};

#endif
