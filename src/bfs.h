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
        vector<string> BreadFirstSearch(string start, Airport airport, vector<string> &bfs_list);
};
   
