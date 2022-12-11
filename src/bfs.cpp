#include <string>
#include <vector>
#include <queue>
#include <list>
#include "bfs.h"
#include <iostream>
using namespace std;

BFS::BFS(){

};
BFS::~BFS(){

};
vector<string> BFS::BreadFirstSearch(string start, Airport airport, vector<string> &bfs_list){ 
    unordered_map<string, vector<pair<string,string>>> airport_adj_list = airport.getAdjList(); //read the routes file and store it in the unordered map
    // the keys of unordered map are the starting airport 
    // the first elements of the pairs in vector are destination, second elements are the airline ids
    if (airport_adj_list.find(start) == airport_adj_list.end()) 
    {
        cout<< "There are no routes from the input starting airport. Try again! " << endl;
        vector<string> vec;
        return vec;  // return a empty vector if the starting airport is not found in the map 
    }
    map<string, bool> visited;
    visited[start] = true;
    queue<string> q;
    q.push(start);
    while (!q.empty())
    {
        string temp = q.front();
        bfs_list.push_back(temp);
        q.pop();
        for (size_t i = 0; i < airport_adj_list[temp].size(); i++)
        {
            if (!visited[airport_adj_list[temp].at(i).first])
            {
                q.push(airport_adj_list[temp].at(i).first);
                visited[temp] = 1;
            }          
            
        }
    }
    vector<string> v = bfs_list;
    return v;
}
