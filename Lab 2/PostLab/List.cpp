
// Jessica Saviano
// jrs5xrw
//1/26/22
#include <iostream>
#include "List.h"
using namespace std;


List::List(){
  head = new ListNode();
  tail = new ListNode();
  head -> next = tail;
  tail-> previous = head;
  head -> previous = NULL;
  tail -> next = NULL;
  count = 0;

}


List::List(const List& source){
    head=new ListNode();
    tail=new ListNode();
    head->next=tail;
    tail->previous=head;
    count=0;

    // Make a deep copy of the list
ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }

  
  }


List::~List(){
  makeEmpty();
  delete head;
  delete tail;
  head = NULL;
  tail = NULL;
  
}


List& List::operator=(const List& source) {
    if (this == &source) {
        // The two are the same list; no need to do anything
        return *this;
    } else {
        // Clear out anything this list contained
        // before copying over the items from the other list
        makeEmpty();

        // Make a deep copy of the list
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

bool List:: isEmpty() const{
  if(((tail->previous) == NULL) & ((head->next == NULL))){
     return  true;
    }
  else{
    return false;
    }
    

}

void List::makeEmpty(){
  count = 0;
  ListItr n9 = ListItr(head->next);
  while(!n9.isPastEnd()){
    ListNode *jess = n9.current -> next;
    remove(n9.current -> value);
    n9.current = jess;
  
    
  }

}


ListItr List::first(){
  ListItr n = ListItr(head ->next);
  return n;

}



ListItr List::last(){
  ListItr n1 =ListItr( tail->previous);
  return n1;

}



void List::insertAfter(int x, ListItr position){
  count +=1;
  ListNode* node1 = new ListNode();
  node1-> value = x;
  node1 ->next = position.current -> next;
 position.current ->next -> previous  = node1;
 position.current -> next = node1;
  node1 -> previous = position.current;
  
  
  

}


void List::insertBefore(int x, ListItr position){
  count +=1;
  ListNode* node2 = new ListNode(); 
  node2-> value = x;
  node2 -> previous =position.current -> previous;
  position.current -> previous -> next = node2;
  position.current -> previous = node2;
  node2 -> next =position.current;

}


void List::insertAtTail(int x){
  count+=1;
  ListNode* node = new ListNode();

  node-> previous = tail-> previous;
  tail->previous->next = node;
  (tail->previous) = node;
  node->value = x;
  node-> next = tail;
  
}

ListItr List::find(int x){

  ListItr n6 = ListItr(head);
  while(!n6.isPastEnd()){
    if(n6.retrieve() != x){
      n6.moveForward();
    }
    if(n6.retrieve() == x){
      return n6;
      
    }
    
      }
    return n6;
    
}


void List::remove(int x){
  ListItr n7 = ListItr(head-> next);
  while(!n7.isPastEnd()){
    if(n7.retrieve() != x){
      n7.moveForward();
    }
    if(n7.retrieve() == x){
      n7.current -> previous -> next = n7.current -> next;
      n7.current -> next -> previous = n7.current -> previous;
      delete n7.current;
      count -=1;
      break;
      
    }
    
      }
       
}

 void printList(List& source, bool forward){
  ListItr n2 = source.first();
  ListItr n3 = source.last();
  if(forward){
    while(!n2.isPastEnd()){
        cout<<(n2.retrieve())<< " ";
	n2.moveForward();
      
           
    }
    
    cout << endl;
  }
    else{
       while(!n3.isPastBeginning()){
        cout<<(n3.retrieve())<< " ";
	n3.moveBackward();

    
    }
    cout << endl;
  }
  
}



int List::size() const{
  
  return count;

}




