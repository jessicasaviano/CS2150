//Jessia Saviano
//jrs5xrw
//2/28/22

// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations

#include "TreeCalc.h"
#include <stack>
#include <stdlib.h>
#include "TreeNode.h"

#include <iostream>

using namespace std;

// Constructor
TreeCalc::TreeCalc() {
  expressionStack = stack<TreeNode*>();
}

// Destructor - frees memory
TreeCalc::~TreeCalc() {
  //cleanTree(expressionStack.top());
}

// Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* tree) {
  if(tree !=NULL){
  if(tree-> right != NULL){
    cleanTree(tree -> right);
  }
    if(tree-> left != NULL){
    cleanTree(tree -> left);
  }
    delete tree;
    

  }
}

// Gets data from user
// DO NOT MODIFY
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0] == '/' || response[0] == '*'
            || response[0] == '-' || response[0] == '+') {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

// Puts value in tree stack
void TreeCalc::insert(const string& val) {
    // insert a value into the tree
  TreeNode* tree = new TreeNode(val);
  if(val != "-" && val != "+" && val != "*" &&  val != "/"){
   
    expressionStack.push(tree);
  }
  else{
    
    tree-> right = expressionStack.top();
    expressionStack.pop();
    tree -> left = expressionStack.top();
    expressionStack.pop();
    expressionStack.push(tree);
  }
}


  
// Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* tree) const {
  if(tree != NULL){
    cout<<tree->value<< " ";
    if(tree->left != NULL){
    printPrefix(tree->left);
    }
    if(tree->right !=NULL){
    printPrefix(tree-> right);

  }
  }
    
}

// Prints data in infix form
void TreeCalc::printInfix(TreeNode* tree) const {
    // print tree in infix format with appropriate parentheses
 
  if(tree != NULL){
    if(tree-> value == "-" ||tree-> value == "+" || tree-> value == "*" ||tree-> value == "/"){
      cout<<"(";
    }
    
    printInfix(tree->left);
    cout << tree->value<< " ";
    printInfix(tree-> right);
      
    
    if(tree-> value == "-" ||tree-> value == "+" || tree-> value == "*" ||tree-> value == "/"){
      cout<<")";
    
    }
  
  }
}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* tree) const {
    // print the tree in postfix form
  if(tree != NULL){
      printPostfix(tree->left);
     printPostfix(tree->right);
    cout<<tree->value<< " ";
    }
  
}

// Prints tree in all 3 (post, in, pre) forms
// DO NOT MODIFY
void TreeCalc::printOutput() const {
    if (expressionStack.size() != 0 && expressionStack.top() != NULL) {
        TreeNode* tree = expressionStack.top();
        cout << "Expression tree in postfix expression: ";
        printPostfix(tree);
        cout << endl;

        cout << "Expression tree in infix expression: ";
        printInfix(tree);
        cout << endl;

        cout << "Expression tree in prefix expression: ";
        printPrefix(tree);
        cout << endl;
    } else {
        cout << "Size is 0." << endl;
    }
}

// Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode* tree) const {
  if(tree-> left ==NULL && tree->right ==NULL){
    return std::stoi(tree->value);
  }
  int ans = 0;
  int right = calculate(tree->right);
  int left = calculate(tree->left);
  if(tree->value == "-"){
   ans =  left - right;

  }
  else if(tree->value == "+"){
   ans = left + right;

  }
  else if(tree->value == "*"){
   ans = left * right;

  }
  else if(tree->value == "/"){
   ans = left / right;

  }
  else{
    ans = stoi(tree -> value);
}
  return ans;
}
//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
 
    // call private calculate method here
  int var =  calculate(expressionStack.top());
  cleanTree(expressionStack.top());
 
  
    return var;
}


