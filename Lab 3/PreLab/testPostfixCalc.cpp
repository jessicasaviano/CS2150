//Jessica Saviano
//jrs5xrw

//2/3/22

#include <iostream>
#include "postfixCalculator.h"
#include <stack>

using namespace std;

int main(){
  int jess;
  postfixCalculator calc;
  string s;
  
  while ( cin >> s){

    if( s == "+"){
      calc.addition();
    }
    else if( s == "-"){
      calc.subtraction();
    }

    else{
        jess = std::stoi(s);
      calc.TheS.push(jess);
    }
  }

    cout <<calc.TheS.top()<< endl;

    return 0;


};
