// Jessica Saviano
// jrs5xrw
// 2/13/22


# include <iostream>
#include <climits>
#include <vector>

using namespace std;

class prelab4{
 public:
  void sizeOfTest();
  void overflow();
  void outputBinary(unsigned int x);
  int x;
  
};
  
 void  prelab4::sizeOfTest(){
  cout << "Size of int: " << sizeof(int) << endl;
  cout << "Size of unsigned int: " << sizeof(unsigned int) << endl;
  cout << "Size of float: " << sizeof(float) << endl;
  cout << "Size of double: " << sizeof(double) << endl;
  cout << "Size of char: " << sizeof(char) << endl;
  cout << "Size of bool: " << sizeof(bool) << endl;
  cout << "Size of int*: " << sizeof(int*) << endl;
  cout << "Size of char*: " << sizeof(char*) << endl;
  cout << "Size of double*: " << sizeof(double*) << endl;



}
void prelab4::overflow(){
   unsigned int jess = UINT_MAX+1;
   unsigned int jess2 = UINT_MAX;
   
   cout << jess2<<" "<< "+"<<" "<<" "<<1<<" "<< "="<<" "<< jess<<endl;

   


 }

 void prelab4::outputBinary(unsigned int x){
   vector<int> arr; 
   while(x != 0){
     arr.push_back(x%2);
     x=x/2;
   }
   while (arr.size() < 32){
     arr.push_back(0);


   }
  

   
   for(int i=arr.size()-1; i > -1; i--){
     if(i == 4 ||i == 8 ||i == 12||i == 16||i == 20||i == 24||i == 28||i == 32){
       cout << arr.at(i)<<' ';
     }
     else{
       cout << arr.at(i) ;
       
  
     }
   
 }
   cout<<endl;
 }

int main(){
  prelab4 jess;
    int x;
    vector<int> arr;
    
    cin >> x;
  jess.sizeOfTest();
  jess.overflow();
    jess.outputBinary(x);
  
 return 0;
 
};

