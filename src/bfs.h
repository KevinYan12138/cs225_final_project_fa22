#pragma once
#include <list>
#include <vector>
#include <string>
#include "airport.h"
#include <map>
using namespace std;

class BFS{
     public: 
        BFS();
        ~BFS();
        //long double BFSdistance(string start, string end, Airport airport);
        //long double BreadFirstSearch(string start, string end, Airport airport, vector<string> &bfs_list);
        vector<string> BreadFirstSearch(string start, Airport airport, vector<string> &bfs_list);
};
   
