// Jessica Saviano
// jrs5xrw
//2/3/22


#include <iostream>
#include <stack>
#include "postfixCalculator.h"

using namespace std;


postfixCalculator::postfixCalculator(){
  stack<int> TheS;
}

postfixCalculator::~postfixCalculator(){

}





void postfixCalculator::addition(){
  int x,y,z;
  if(!TheS.empty()){
   
    x = TheS.top();
    TheS.pop();
    y = TheS.top();
    TheS.pop();
    z = x+y;
    TheS.push(z);
  }
}
    


void postfixCalculator::subtraction() {
  int a,b,c;
  if(!TheS.empty()){
    a = TheS.top();
    TheS.pop();
    b = TheS.top();
    TheS.pop();
    c = b-a;
    TheS.push(c);
  }
 
}


