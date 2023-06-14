
//Jessica Saviano
//jrs5xrw

//2/3/22

#include <iostream>
#include "postfixCalculator.h"


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

    else if( s == "/"){
      calc.division();
    }

    else if( s == "*"){
      calc.multiplication();
    }

     else if( s == "~"){
      calc.negation();
    }


    else{
       float jess = std::stof(s);
       int jess2 = (int)jess;
      calc.TheS.push(jess);
    }
  }
 
    cout <<calc.TheS.top()<< endl;

    return 0;


};
