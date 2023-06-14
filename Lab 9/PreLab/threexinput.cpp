//Jessica Saviano, Jrs5xrw

#include <iostream>
#include <cstring>
using namespace std;

extern "C" int threexplusone(unsigned int x);


int main(){

  int x,n,res;
  
  cout << "Enter a number: ";
  cin >> x;
 
  
  cout << "Enter iterations of subroutine: ";
  cin >> n;

  res = threexplusone(x);
  cout << "Steps: " << res << endl;
   

  return 0;

}
