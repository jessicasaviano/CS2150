//jrs5xrw, Jessica Saviano

#include "heapNode.h"
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <map>

using namespace std;

heapNode::heapNode(char letter, int freq){
  letter1 = letter;
  freq1 = freq;
  rightC = NULL;
  leftC = NULL;

}

heapNode::heapNode(){
  letter1 = '#';
  freq1 = 0;
  rightC = NULL;
  leftC = NULL;

}

bool heapNode::leaf(heapNode* r){
  if(r->rightC == NULL && r->leftC == NULL){
    return true;

  }
  return false;
}
