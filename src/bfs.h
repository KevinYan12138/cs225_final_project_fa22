#pragma once
#include <list>
#include <vector>
#include <string>
#include "airport.h"
#include <map>
using namespace std;

class BFS{
     public: 
        /*
         The constructor for the BFS class
        */
        BFS();
        /*
        The destructor for the BFS class
        */ 
        ~BFS();
        /*
        The BreadthFirstSearch algorithm
        It takes in a starting airport ID, the airport object we are going to traverse, and a vector of strings to store it
        BreadthFirstSearch will return all the airports that the we can arrive from the starting airport
        These airports will be stored in a vector of airport IDs, the starting airport will be the element at the 0th index
        */
        vector<string> BreadthFirstSearch(string start, Airport airport, vector<string> &bfs_list);
};
   
