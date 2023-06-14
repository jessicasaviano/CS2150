
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





ListItr List::first(){
  ListItr n = ListItr(head ->next);
  return n;

}



ListItr List::last(){
  ListItr n1 =ListItr( tail->previous);
  return n1;

}
bool List::isEmpty() const{
  return true;

}

void List::makeEmpty(){

}

ListItr List::find(int x){
  return 0;
}


void List::insertAfter(int x, ListItr position){

}


void List::insertBefore(int x, ListItr position){

}


void List::insertAtTail(int x){
  ListNode* node = new ListNode();
  count +=1;
  node-> previous = tail-> previous;
  tail->previous->next = node;
  (tail->previous) = node;
  node->value = x;
  node-> next = tail;
  



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
  
}


void List::remove(int x){

}


int List::size() const{
  
  return count;

}




