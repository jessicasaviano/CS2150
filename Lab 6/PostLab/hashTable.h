//Jessica Saviano
//jrs5xrw
//3/15/22
//hashTable.h
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
  
  int xton(int a, int b);
   bool checkprime(unsigned int p);
  int getNextPrime(unsigned int n);
  


 private:
  
  vector<list<string> > myH;
  
  unsigned int hashF(string s);  
  
};
  
 #endif
  
  
  
