
// Jessica Saviano
// jrs5xrw
//1/26/22
#include <iostream>
#include "stack.h"
#include "StackNode.h"
using namespace std;

stack::stack(){
  head = new StackNode();
  count = 0;
  
}

stack:: ~stack(){
  empty();
  head = NULL;
  count = 0;
}

bool stack::empty() const{
  if(count == 0){
    return true;
  }
  return false;

}


void stack::push(int val){
  
  StackNode* n = new StackNode();
  count+=1;
  n -> value = val;
  n -> previous = head -> previous;
  head -> previous = n;


}


void stack::pop(){
  count -= 1;
  if(!empty()){
    if(head -> previous -> previous != NULL){
    StackNode* temp = head ->previous;
    head -> previous = head -> previous -> previous;
    delete temp;
    }
    else{
      delete head ->previous;

    }
  }

}
int stack::top() const{
  
  if(!empty()){
  
    return head ->previous -> value;
    
    
  }
 
  exit(-1);
  
}

