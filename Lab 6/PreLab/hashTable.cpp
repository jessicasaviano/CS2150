#include <iostream>
#include <vector>
#include <list>
#include "hashTable.h"


using namespace std;


hashTable::hashTable(){
  
  myH.resize(521);

  for(int i = 0 ; i < myH.size(); i++){
    list<string> *list2 = new list<string>();
    myH[i] = *list2;

  }
}

hashTable::~hashTable(){
  
  

}


hashTable::hashTable(unsigned int s){
  
  
}


bool hashTable::contains(string st){
  vector<list<string> >::iterator itr;
  for( itr = myH.begin(); itr != myH.end(); itr++){
    if(itr->empty()){
      return false;
    }
    else{
      for(list<string>::iterator it = itr->begin(); it != itr->end(); it++){
	if(st == *it){
	  return true; 
	}
      }
     
    }
  }
   return false;
   
}

void hashTable::insert(string str){
  
  int index = hashF(str);
  myH[index].push_back(str);
  


}



unsigned int hashTable::hashF(string s){
  int result = 0;
  int arr[] = {37,1369,50653,187161,69343957};
  
     
  for(int i = 0; i < s.length();i++){
    if(s.length() > 5) break;
	
    result += s[i]* arr[i];

  }
  return result % myH.size();
  

}


int hashTable::getNextPrime(unsigned int n){
  while (!checkprime(++n)) {
    return n; // all your primes are belong to us
  }
  return n;
}



bool hashTable::checkprime(unsigned int p){
  if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;

}


