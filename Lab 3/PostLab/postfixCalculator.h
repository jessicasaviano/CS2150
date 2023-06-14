// Jessica Saviano
// jrs5xrw
// 2/3/22

#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include <iostream>
#include "stack.h"

using namespace std;


class postfixCalculator {

 public:
  postfixCalculator();

  ~postfixCalculator();
  
  void addition();
  
  void subtraction();

  void multiplication();

  void division();

  void negation();
  
  stack TheS;
};

 #endif

  

   
			       


			       
