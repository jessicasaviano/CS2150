#include <iostream>
using namespace std;


int xton(int a, int b){
  if(b == 0){
    return 1;
  }
  else{
    return a * xton(a, b-1);
  }
}

int main(){
  int a;
  int b;
  int c;
  cin>> a;
  cin>> b;
  c = xton(a,b);
  cout<< c  << endl;
  return 0;
}
