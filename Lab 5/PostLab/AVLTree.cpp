//Jessica Saviano
//Jrs5xrw
//3/3/22



#include "AVLNode.h"
#include "AVLTree.h"
#include <iostream>
#include <string>
using namespace std;

AVLTree::AVLTree() {
    root = NULL;
}

AVLTree::~AVLTree() {
    delete root;
    root = NULL;
}

// insert finds a position for x in the tree and places it there, rebalancing
// as necessary.
void AVLTree::insert(AVLNode*& node1, const string& x){
   
 if(node1 == NULL){
    node1 = new AVLNode();
    node1-> value = x;
  }
  
  else if( node1->value > x){
  insert(node1-> left,x);
    
  }
 
  
  else if(node1->value < x){
    insert(node1->right,x);
  }
  else if(node1->value == x){

    ;
  }

  
  balance(node1);
  node1->height = 1 + max(height(node1->left), height(node1->right));
  

    
}
  

void AVLTree::insert(const string& x) {
    // YOUR IMPLEMENTATION GOES HERE
  insert(root,x);
 
  
}

// remove finds x's position in the tree and removes it, rebalancing as
// necessary.
void AVLTree::remove(const string& x) {
    root = remove(root, x);
}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.

string AVLTree::pathTo(AVLNode* node1, const string& x) const {
  
   if(node1->value == x){
      return x;
      

    }
    if(node1 -> value < x){
      return node1 ->value +" " + pathTo(node1->right,x); 
    
  }
    else if(node1->value >x){
      return node1 -> value + " "+  pathTo(node1->left,x) ;
  }

    else{
 
      return "";
    }
}

string AVLTree::pathTo(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
  if(find(x) == false){
    return " ";
  }
  else{
    return pathTo(root, x);
  }

  
}






// find determines whether or not x exists in the tree.
bool AVLTree::find(AVLNode* node1, const string& x) const {

  if(node1 == NULL){
    return false;
  }
  else if(node1->value == x){
      return true;
      
    }
    else if(node1-> value < x){
      return find(node1->right, x);
    }
     else if(node1-> value > x){
      return find(node1->left, x);
    }

  
  
  return false;
 
}

bool AVLTree::find(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
  if(!find(root, x))
     return false;
  
   else{
    return true;
  }

}
int AVLTree::numNodes(AVLNode* node1) const {
 
  if(node1== NULL){
  return 0;
  }
  else{
  return  numNodes(node1->left) + numNodes(node1->right) +1;
 
  
  }
  
  

}

// numNodes returns the total number of nodes in the tree.
int AVLTree::numNodes() const {
    // YOUR IMPLEMENTATION GOES HERE
  if(root == NULL){
    return 0;
  }
  else{
    return numNodes(root);
  }
 
}



// balance makes sure that the subtree with root n maintains the AVL tree
// property, namely that the balance factor of n is either -1, 0, or 1.
void AVLTree::balance(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE

   int  balance_factor = height(n->right)-height(n->left);
  


  if(balance_factor ==2){
    int  balance_factor_right = height(n->right->right)-height(n->right->left);
    if(balance_factor_right < 0){
      n->right = rotateRight(n->right);
    }
    
     n= rotateLeft(n);


  }
  else if(balance_factor == -2){
    int balance_factor_left = height(n->left->right)-height(n->left->left);
    if(balance_factor_left > 0){
      n-> left = rotateLeft(n->left);
    }
   
      n = rotateRight(n);
      

      
    
      
  }

}
  

// rotateLeft performs a single rotation on node n with its right child.
AVLNode* AVLTree::rotateLeft(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
 
  AVLNode* right_n = n->right;
 
  
  n->right = right_n->left;
  right_n-> left = n;

  right_n->height = max(height(right_n->right), height(right_n->left)) +1;
  n->height = max(height(n->right), height(n->left)) +1;

  return right_n;
}

// rotateRight performs a single rotation on node n with its left child.
AVLNode* AVLTree::rotateRight(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
 
  AVLNode* left_n = n -> left;
  
    n-> left = left_n -> right;
  left_n->right = n;

  

  left_n->height = max(height(left_n->right->right), height(left_n->right->left)) +1;
  n->height = max(height(n->right), height(n->left)) +1;
  return left_n;
}

// private helper for remove to allow recursion over different nodes.
// Returns an AVLNode* that is assigned to the original node.
AVLNode* AVLTree::remove(AVLNode*& n, const string& x) {
    if (n == NULL) {
        return NULL;
    }

    // first look for x
    if (x == n->value) {
        // found
        if (n->left == NULL && n->right == NULL) {
            // no children
            delete n;
            n = NULL;
            return NULL;
        } else if (n->left == NULL) {
            // Single child (left)
            AVLNode* temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        } else if (n->right == NULL) {
            // Single child (right)
            AVLNode* temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        } else {
            // two children -- tree may become unbalanced after deleting n
            string sr = min(n->right);
            n->value = sr;
            n->right = remove(n->right, sr);
        }
    } else if (x < n->value) {
        n->left = remove(n->left, x);
    } else {
        n->right = remove(n->right, x);
    }

    // Recalculate heights and balance this subtree
    n->height = 1 + max(height(n->left), height(n->right));
    balance(n);

    return n;
}

// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode* node) const {
    // go to bottom-left node
    if (node->left == NULL) {
        return node->value;
    }
    return min(node->left);
}

// height returns the value of the height field in a node.
// If the node is null, it returns -1.
int AVLTree::height(AVLNode* node) const {
    if (node == NULL) {
        return -1;
    }
    return node->height;
}

// max returns the greater of two integers.
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

// Helper function to print branches of the binary tree
// You do not need to know how this function works.
void showTrunks(Trunk* p) {
    if (p == NULL) return;
    showTrunks(p->prev);
    cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void AVLTree::printTree(AVLNode* root, Trunk* prev, bool isRight) {
    if (root == NULL) return;

    string prev_str = "    ";
    Trunk* trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight) {
        trunk->str = ".---";
        prev_str = "   |";
    } else {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->value << endl;

    if (prev) prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);

    delete trunk;
}

void AVLTree::printTree() {
    printTree(root, NULL, false);
}
