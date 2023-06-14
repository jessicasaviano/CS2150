// Jessica Saviano
// jrs5xrw
// 2/7/22

#ifndef STACK_H
#define STACK_H
#include "StackNode.h"

#include <iostream>

using namespace std;


class stack{

 public:

  stack();
  ~stack();
  bool empty() const;
  void push(int val);
  void pop();
  int top() const;

private:
  StackNode *head;
  int count;

};


#endif

