
// Jessica Saviano
// jrs5xrw
// 2/13/22


#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class bitCounter{
 public:
  int binaryBit(unsigned int n);
  string baseConverter(string str, int start, int end);
  int n;
  
};
  
int bitCounter::binaryBit(unsigned int n){
  if(n == 0){
      return 0;
     }

   else if(n == 1){
      return 1;
     }
   
    
   if(n%2 == 0){
      return binaryBit(n/2);
	}
	
    else{
      return 1+binaryBit(floor(n/2));

  }
  
}


string bitCounter::baseConverter(string str, int start, int end  ){
  char con_num = 0;
  int count = str.length() -1;
  int base = 0;
  vector <char> arr;

   for(int i = 0; i < str.length(); i++){
     if((str[i] == '0') ||(str[i] == '1') ||(str[i] == '2') ||(str[i] == '3')||(str[i] == '4') ||(str[i] == '5')||(str[i] == '6') ||(str[i] == '7')||(str[i] == '8') ||(str[i] == '9')){
	 con_num = str[i] -48;
   }
   
       else{
	 con_num = str[i] - 55;       

       }

  
     
       base = base + (con_num * pow(start, count));
      
       count -=1;
}

  
   
    while(base > 0){
       
       if(base%end != 0){
	
	 arr.push_back(base%end);
	
       } else {

	 arr.push_back(0);
       }
      
       base/=end;
       
     }

     string s2 = "";
     char jess2 = ' ';
     for(int i = arr.size()-1; i >= 0; i--){
       if((arr.at(i) == 0) ||(arr.at(i) == 1) ||(arr.at(i) == 2) ||(arr.at(i) == 3)||(arr.at(i) == 4) ||(arr.at(i) == 5)||(arr.at(i) == 6) ||(arr.at(i) == 7)||(arr.at(i) == 8) ||(arr.at(i) == 9)){
	 jess2 = arr.at(i)+48;
   
   
       } else{
	 jess2  =arr.at(i) + 55;       

       }
      
       s2 += jess2;
      
     }
     
     return s2;
   
   }

int main( int argc, char **argv){
  bitCounter jess2;
   
      
      int n = atoi(argv[1]);
      string str = argv[2];
      int start =  atoi(argv[3]);
      int end = atoi(argv[4]);
      
      
      
      cout << n <<" "<< "has"<< " " << jess2.binaryBit(n)<<" " << "bit(s)"<<endl;
   
      cout << str << " " << "(" << "base"<< " "<<start<<")" << " "<< "=" <<" "<< jess2.baseConverter(str,start,end) << " "<< "(" << "base"<<" "<<end<<")"<< endl;
      
 
 return 0;
 
};


