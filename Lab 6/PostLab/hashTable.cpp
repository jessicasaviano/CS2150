//Jessica Saviano
//jrs5xrw
//3/15/22
//hashTable.cpp

#include <iostream>
#include <vector>
#include <list>
#include "hashTable.h"


using namespace std;


hashTable::hashTable(unsigned int s){
   int x = getNextPrime(s*3);
  myH.resize(x);
  //postlab , check each line icnrmemebt, while for inserting, incrementnc ount
  //wordpuzzle solve

  // for(int i = 0 ; i < x; i++){
    //list<string> *list2 = new list<string>();
  // myH[i] = *list2;

  //}
}

hashTable::~hashTable(){
  
  

}


hashTable::hashTable(){
  
  
}

int hashTable::xton(int a, int b){
  if(b == 0){
    return 1;
  }
  else{
    return a * xton(a, b-1);
  }
}


bool hashTable::contains(string st){
  list<string> ::iterator itr;

 int d = hashF(st);

  
  for(itr = myH[d].begin(); itr != myH[d].end(); itr++){
    if(*itr ==st)
      return true;
  }
   return false;
   
}

void hashTable::insert(string str){
  
  int index = hashF(str);
 
  myH[index].push_back(str);
  //cout << myH[index].back() << endl;
  


}



unsigned int hashTable::hashF(string s){
  int result = 0;
  //int arr[] = {37,1369,50653,187161,69343957};
  
     
  for(int i = 0; i < s.length();i++){
    // if(s.length() > 5) break;
	
    result += s[i]* xton(37,i);

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


