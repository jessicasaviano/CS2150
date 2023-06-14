//Jessica Saviano
// jrs5xrw
// 2/7/22

#ifndef STACKNODE_H
#define STACKNODE_H

#include <iostream>

using namespace std;


class StackNode {

 public:
  StackNode();

 private:
  friend class stack;
  int value;
  StackNode* previous;
 

};

#endif
