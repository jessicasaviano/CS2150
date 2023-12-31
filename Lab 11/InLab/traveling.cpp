#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

#include "middleearth.h"

/**
 * @attention make sure you understans what permutations mean!
 */


/**
 * @brief this file uses/expands on methods in middleearth
 */



float computeDistance(MiddleEarth& me, const string& start, vector<string> dests);
void printRoute(const string& start, const vector<string>& dests);

int main(int argc, char** argv) {
    // check the number of parameters
    if (argc != 6) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }

    // we'll assume the parameters are all well-formed
    int width = stoi(argv[1]);
    int height = stoi(argv[2]);
    int num_cities = stoi(argv[3]);
    int rand_seed = stoi(argv[4]);
    int cities_to_visit = stoi(argv[5]);

    // create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);
    
    // TODO: YOUR CODE HERE

    string start1 = dests[0];
    float jess = 0.0;
    float shortest  = computeDistance(me, start1, dests);
   
    sort(dests.begin()+1, dests.end());
    
    vector<string> jess1 = dests;
    while(std::next_permutation(dests.begin()+1, dests.end())){
	jess = computeDistance(me, start1, dests);
	if(jess < shortest){
	  shortest = jess;
	  jess1 = dests;
	}
	//else if(jess == shortest){
	//break;
	//	}
      }
	

      cout << "Minimum path has distance: " << shortest << ": ";
      printRoute(start1, jess1);





    
    return 0;
}

// This method will compute the full distance of the cycle that starts
// at the 'start' parameter, goes to each of the cities in the dests
// vector IN ORDER, and ends back at the 'start' parameter.
float computeDistance(MiddleEarth& me, const string& start, vector<string> dests) {
    // TODO: YOUR CODE HERE
  float d1 = 0.0;
  string a = start;
  d1 += me.getDistance(start, dests.at(0));
  for(int i = 1; i < dests.size(); i ++){
    d1 += me.getDistance(a, dests.at(i));
    a = dests.at(i);

  }
  
  d1+= me.getDistance(dests.at((dests.size()-1)),start);

    
    return d1;
}

// This method will print the entire route, starting and ending at the
// 'start' parameter.
// The output should be similar to:
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
void printRoute(const string& start, const vector<string>& dests) {
    // TODO: YOUR CODE HERE
  
  for(int i =0; i < dests.size(); i++){
    cout << dests.at(i) << " " << "->"<< " ";
    

  }
  cout<<start<< " "<<endl;
}
