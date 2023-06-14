//Jessica Saviano Jrs5xrw

#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

extern "C" long product (long, long);

extern "C" long power (long, long);

int main() {

  int x, y;
  int prod, pow;
 
  
  cout << "Enter integer 1: " ;
  cin >> x;

  cout << "Enter integer 2: " ;
  cin >> y;

  prod = product(x,y);
  cout << "Product: " << prod << endl;
  
  pow = power(x,y);
  cout << "Power: " << pow << endl;


  return 0;
}
