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
        long double BreadFirstSearch(string start, string end, Airport airport);
        //unordered_map<string, vector<pair<string,string>>> airport_adj_list;
};
   
