#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <vector>
#include <list>


using namespace std;




class hashTable{
 public:

  hashTable();
  hashTable(unsigned int s);
  ~hashTable();
  bool contains(string st);
  void insert(string str);


 private:
  vector<list<string> > myH;
  bool checkprime(unsigned int p);
  int getNextPrime(unsigned int n);
  unsigned int hashF(string s);  
  
};
  
 #endif
  
  
  
