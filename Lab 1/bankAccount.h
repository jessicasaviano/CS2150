// Jessica Saviano
// jrs5xrw
//1/26/22

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H


#include <iostream>
#include <string>

using namespace std;

// Declare the BankAcc class

class bankAccount {
  
 public:
  bankAccount(); //default
  
  bankAccount(double amount); //constructor with parameter
  
  ~bankAccount(); //deconstructor
  
  double deposit(double amount);
  double withdraw(double amount);

  double getBalance() const;


 private:
  double balance;



};


#endif
