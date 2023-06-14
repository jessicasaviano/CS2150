#include <unordered_map>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;


/**
 * @attention Understand breadth first search
 */


/**
 * @brief this code solves the puzzle game for the postlab
 */

//string state;
  string goal = "123456780";
  vector<string> j2;
  unordered_map<string, int> j; //visited variation already
  queue<string> q; //breadth first search
vector<string> generateNeighbors(string curr);
int Sort(string s);

int main(){
  string s1, s2, s3;
  //string s2;
  //string s3;
  cout << "Enter puzzle" << endl;
   
   getline(cin, s1);
   getline(cin, s2);
   getline(cin, s3);
   
  cout << "Solving puzzle" << endl;
  
  string temp = s1+ s2 + s3;

  string state;
  for( int i = 0; i < temp.length(); i++){
    if(temp[i] != ' '){
      state += temp[i];

  }
  }
  //cout << state << endl;
  //v is configuration you just recently popped off, w is for each of the nehigobsr
  //after you popp v of fyou are going ot generate neighbors and loop throuhg them

  //if(w is in my map) continue;
  // if it is NOt in my map, insert it in map, j[w] = j[v]+1
  //and then im going to push it on
  //if( it is equal to goal)
  //break
  //then I have to print the maps value of goal string

  
  //j2 =  generateNeighbors(state);
  //cout << j2[0] << " " << j2[1] << endl;
   
  int ans = Sort(state);

  if(ans == -1){
    cout << "IMPOSSIBLE" << endl;
  }
  else{
    cout << ans << endl;
  }





  
  //old stuff below v
  //call generate neighbors
  //use genreate neighbors in breadth for sort algo
  // set it to a temporary vector
  //puhs them all onto the queue
  //
  //throw into unordered map after popping off queue


  
  //for each node im working on, going to generate neigbors, then throw them back onot end of queue, then go to next one,
  //put starting in queue
  //keepdoing thsi until you reach  anode with configuration ur looking for, that will be shortest distance
 //





  return 0;
}
  

vector<string> generateNeighbors(string curr){
  //will return list of what can be moved with the 0 in the string given
  //breadth for search
  //blokc it off in chunks, if the index is not in bottom row then , two more if statemnts for left and right and check if it is not equal to any on left or right
  //

  //
  vector<string> j1;
  string t0 = curr;
  string t1 = curr;
  string t2 = curr;
  string t3 = curr;
  if(curr[0] == '0'){
    swap(curr[0],curr[3]);
    j1.push_back(curr);
    swap(t0[0],t0[1]);
    j1.push_back(t0);

  }
  else if (curr[1] == '0'){
     swap(curr[1],curr[4]);
    j1.push_back(curr);
    swap(t0[1],t0[0]);
    j1.push_back(t0);
    swap(t1[1],t1[2]);
    j1.push_back(t1);



  }
   else if (curr[2] == '0'){
      swap(curr[2],curr[1]);
    j1.push_back(curr);
    swap(t0[2],t0[5]);
    j1.push_back(t0);


  }
   else if (curr[3] == '0'){
     swap(curr[3],curr[0]);
    j1.push_back(curr);
    swap(t0[3],t0[6]);
    j1.push_back(t0);
    swap(t1[3],t1[4]);
    j1.push_back(t1);



  }
   else if (curr[4] == '0'){
     swap(curr[4],curr[1]);
    j1.push_back(curr);
    swap(t0[4],t0[3]);
    j1.push_back(t0);
    swap(t1[4],t1[5]);
    j1.push_back(t1);
     swap(t2[4],t2[7]);
     j1.push_back(t2);



  }
   else if (curr[5] == '0'){
    swap(curr[5],curr[2]);
    j1.push_back(curr);
    swap(t0[5],t0[4]);
    j1.push_back(t0);
    swap(t1[5],t1[8]);
    j1.push_back(t1);



  }
   else if (curr[6] == '0'){
       swap(curr[6],curr[3]);
    j1.push_back(curr);
    swap(t0[6],t0[7]);
    j1.push_back(t0);
   



  }
   else if (curr[7] == '0'){
      swap(curr[7],curr[4]);
    j1.push_back(curr);
    swap(t0[7],t0[6]);
    j1.push_back(t0);
    swap(t1[7],t1[8]);
    j1.push_back(t1);



  }
   else if (curr[8] == '0'){
     swap(curr[8],curr[7]);
    j1.push_back(curr);
    swap(t0[8],t0[5]);
    j1.push_back(t0);
   



  }
  return j1;
  
}


int Sort(string s){
  if(s == goal){
    return 0;
  }
  j[s] = 0;
  q.push(s);
  while(q.empty() == false){
  
    string state = q.front();
    //cout << v << endl;
    q.pop();
    j2 =  generateNeighbors(state);
    //cout << j2[0] << endl;
    for(int i = 0; i < j2.size(); i ++){
      //cout << j2[0] << endl;
      if(j.find(j2[i]) == j.end()){
	j[j2[i]] = j[state] +1;
	q.push(j2[i]);
      
	if(j2[i] == goal){
	  return j[state] +1;
	}
	  
      }
	  
    }


  }
  
  return -1;
  
}
    

  







