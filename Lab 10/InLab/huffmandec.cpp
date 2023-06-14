
// Jessica Saviano, Jrs5xrw, inspo from the skeleton code provided.

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include "heapNode.h"
using namespace std;
void Huffman(heapNode* node,char c, string code);
//void getChar(heapNode* node, string encode);

// main(): we want to use parameters
int main (int argc, char** argv) {
  heapNode* node = new heapNode();
  heapNode* root = new heapNode();
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // must be opened in binary mode as otherwise trailing whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    // read in the first section of the file: the prefix codes
    while (true) {
        string character, prefix;
        // read in the first token on the line
        file >> character;

        // did we hit the separator?
        if (character[0] == '-' && character.length() > 1) {
            break;
        }

        // check for space
        if (character == "space") {
            character = " ";
        }

        // read in the prefix code
        file >> prefix;
        // do something with the prefix code

	Huffman(root, character[0], prefix);
	
    }
    //    cout << root->rightC->leftC->leftC->letter1<<endl;
	   	

   
    // read in the second section of the file: the encoded message
    stringstream sstm;
    // node = root;
    while (true) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if (bits[0] == '-') {
            break;
        }
        // add it to the stringstream
        sstm << bits;
    }
    

    
    string allbits = sstm.str();
    node = root;
      
    for(int i = 0; i <= allbits.length(); i ++){
      if(node-> rightC == NULL && node->leftC == NULL){
	cout << node->letter1;
	node = root;
      }

      if(allbits[i] == '0'){
	  node = node->leftC;
	  //node = root;
      }
	

     
      if(allbits[i] == '1'){
	  node = node->rightC;
	  //node = root;
	}
      
    }
    cout << endl;
   


    
    // getChar(node, allbits);

    
    // at this point, all the bits are in the 'allbits' string
    
    // close the file before exiting
    file.close();

    return 0;

}

void Huffman(heapNode* node, char c,  string code){
  char j = code[0];
   if(j == '0'){
     if(node -> leftC == NULL && code.substr(1) == ""){	
       node-> leftC = new heapNode(c,1);
     }
	
    
     else if(node -> leftC == NULL && code.substr(1) != ""){
      node-> leftC = new heapNode('-',1);
      Huffman(node->leftC, c, code.substr(1));
     }
	     
     
      else{
       Huffman(node->leftC, c, code.substr(1));
      }
     
   }

   else{
    if(node -> rightC == NULL && code.substr(1) == ""){
	
      node-> rightC = new heapNode(c,1);
	
    }
    else if(node -> rightC == NULL && code.substr(1) != ""){
      node-> rightC = new heapNode('-',1);
      Huffman(node->rightC, c, code.substr(1));

    }
    else{
       Huffman(node->rightC, c, code.substr(1));
    }
   }
   
}
    

/*
void getChar(heapNode* node, string encode){
  char j = encode[0];
 
  if(node-> rightC == NULL && node->leftC == NULL){
    //cout << node->letter1;
  }
  if (encode.substr(1) != ""){
    
    
    if(j == '0'&& node->leftC != NULL){
      cout <<node->letter1<<endl;
      getChar(node->leftC, encode.substr(1));
      
  }
    else if(j  == '1'&& node->rightC != NULL){
      cout << node->letter1 <<endl;
      getChar(node->rightC,encode.substr(1));
     
  }
     
  }
}
*/
