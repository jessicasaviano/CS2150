// jrs5xrw, inspo from fileio example
// Jessica Saviano



// This program shows how C++-based file I/O works.
// It will print a file to the screen two times.
//inspo from file io

// included so we can use cout,
#include <iostream>
// file I/O
#include <fstream>
// cstdlib is where exit() lives
#include <cstdlib>

#include <unordered_map>
#include"heap.h"
#include "heapNode.h"

using namespace std;

// we want to use parameters
void codeprint(heapNode* r1, string c);
unordered_map<char, string> m1;
int main(int argc, char** argv) {
  //int x[10000];
  
  // verify the correct number of parameters
  if (argc != 2) {
    cout << "Must supply the input file name as the one and only parameter" << endl;
    exit(1);
  }

  // attempt to open the supplied file
  // ifstream stands for "input file stream"
  ifstream file(argv[1]);
  // if the file wasn't found, output an error message and exit
  if (!file.is_open()) {
    cout << "Unable to open '" << argv[1] << "' for reading" << endl;
    exit(2);
  }

  // read in characters one by one, until reading fails (we hit the end of the file)
   char g;
  unordered_map<char, int> hmap;
  int symbol_counter = 0;
  int distinct = 0;
  while (file.get(g)) {
      if((g < 32) || (g > 126)){
	
      continue;
    }
     symbol_counter++;

    
    if(hmap.find(g) != hmap.end()){
	
    hmap[g]++;
      }
      
   else{
   distinct++;
       hmap[g] = 1;	
        
    }
    
  }
  //for(unordered_map<char, int>::iterator it = hmap.begin(); it != hmap.end(); it++){
  // cout << " "<< it->first << " " << it-> second << endl;
  // }
    
   heap h1;
   for(unordered_map<char, int>::iterator it = hmap.begin(); it != hmap.end(); ++it){
        
     heapNode* newN = new heapNode(it->first, it->second);
       h1.insert(newN);
      
      
   }


  
  while(h1.size() > 1){
    heapNode* internal = new heapNode();
    internal->freq1 += h1.findMin()->freq1;
    internal->leftC = h1.findMin();
    h1.deleteMin();
    internal->freq1 += h1.findMin()->freq1;
    internal->rightC = h1.findMin();
    h1.deleteMin();
    h1.insert(internal);
      

  }
    
  codeprint(h1.findMin(), "");

  cout << "----------------------------------------" << endl;
    
  file.clear();
  file.seekg(0);
  
  // Read the file again, and print to the screen
  string bit = "";
  string bit1= "";
  while (file.get(g)) {
    if((g < 32) || (g > 126)){
      continue;
    }
      
    
      bit1 += m1[g] + " ";
      bit += m1[g];
      
      
  }
  cout <<bit1 << " "<<endl;
  // close the file
  file.close();

  cout << "----------------------------------------" << endl;


  int sym = symbol_counter*8;
  float comp = ((float)sym)/((float)bit.length());
  float huff = ((float)bit.length())/((float)symbol_counter);
  cout << "There are a total of"<<" " << symbol_counter <<" "<< "symbols that are encoded."<< endl;
  cout<< "There are" << " "<< distinct <<" "<< "distinct symbols used."<<endl;
  cout <<"There were"<<" "<< sym <<" "<<"bits in the original file." <<endl;

  cout <<"There were"<<" "<< bit.length() <<" "<<" bits in the compressed file." << endl;
  cout<<"This gives a compression ratio of"<<" "<< comp<<"."<<endl;
  cout<<"The cost of the Huffman tree is"<<" "<< huff<<" "<<"bits per character."<<endl;

  // once we hit the end of the file we are marked as "failed", so clear that
  // then "seek" to the beginning of the file to start again
  //file.clear(); // Clears the _state_ of the file, not its contents!
  //file.seekg(0);
    
  return 0;





    

    
}


void codeprint(heapNode* r1, string c){
  heap h;
  if (r1->leaf(r1)){
    
    if(r1->letter1 == ' '){
    
      cout << "space " << c << endl;
    }

    if(r1->letter1 != ' '){
      cout << r1->letter1 <<" "<<  c << endl;

    }
  
    m1[r1->letter1] = c;
  }
  else{
    if(r1->leftC != NULL){

      codeprint(r1->leftC, c+ "0");
      

    }
    if(r1->rightC != NULL){
      
      codeprint(r1->rightC, c + "1");
      


    }
  }

}
