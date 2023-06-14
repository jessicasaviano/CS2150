// This program shows how C++-based file I/O works.
// It will open a file, read in the first two strings, and print them to the screen.

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <deque>          // std::deque
#include <list>           // std::list
#include <queue>          // std::queue
#include <deque>
#include <array>

using namespace std;

vector<int> indegree;
vector<string> jess;

/**
 * @attention make sure your file has two "columns" of strings!
 */


/**
 * @brief this ode will do a topological sort for cs prereqs
 */

// we want to use parameters
int main(int argc, char** argv) {
  // verify the correct number of parameters
  if (argc != 2) {
    cout << "Must supply the input file name as the one and only parameter" << endl;
    exit(1);
  }

  // attempt to open the supplied file
  ifstream file(argv[1], ifstream::binary);
  // report any problems opening the file and then exit
  if (!file.is_open()) {
    cout << "Unable to open file '" << argv[1] << "'." << endl;
    exit(2);
  }
    
  // read in two strings
  while(true){
    string s1, s2;
    file >> s1;
    file >> s2;
    
     if (s1 == "0" && s2 == "0") {
      break;
    }
    //cout << s1<<  << endl;
    if(std::find(jess.begin(),jess.end(),s1) == jess.end()){
      //cout << s1 << endl;
      jess.push_back(s1);
      
    }
      
    //cout << s2 << endl;
    if(std::find(jess.begin(),jess.end(),s2) == jess.end()){
      //cout << s2 << endl;
      jess.push_back(s2);
    }
 
  }



    
   file.clear();
    file.seekg(0);
   
    
    int j1 = jess.size();
  int m[j1][j1];
  for(int i = 0; i < j1; i++){
    indegree.push_back(0);
    for(int j =0; j< j1; j++){
      m[i][j] = 0;
    }
  }
  
  
  //cout << jess[0]<< endl;
  while(true){
    string s1, s2;
    file >> s1;
    file >> s2;
    //cout << s1 << s2 << endl;
    
    if (s1 == "0" && s2 == "0") {
      break;
    }
    
    for(int i = 0; i < j1; i++){

      if(jess.at(i) == s1){
	for(int j = 0; j < j1; j++){
	  if(jess.at(j) ==s2){
	    m[i][j] = 1;
	    // cout << s1 << s2 << endl;
	    indegree.at(j)++;
	    //cout << s1 << s2 << endl;
	  }
	}

      }
    }
  }
  //cout << jess[0]<< endl;
  
  file.close();
  
queue<string> q;
for(int i =0; i < j1; i++){
  //cout << jess[i] << " "<< indegree[i]<<  endl;
  if(indegree[i] == 0){
    q.push(jess[i]);    
 }
 }
 while(!q.empty()){
   string j2 = q.front();
   q.pop();
   cout << j2 << " " ;
   for(int j = 0; j < j1; j++){
      if(jess.at(j) == j2){
	for(int k = 0; k < j1; k++){
	  if(m[j][k] == 1){
	    indegree[k]--;
	    if(indegree[k] == 0){
	    q.push(jess[k]);
	    }
	 
	  }
	}
      }
   
   }
 }


 cout << endl;      
  
  
  file.close();
 
 return 0;
 }



