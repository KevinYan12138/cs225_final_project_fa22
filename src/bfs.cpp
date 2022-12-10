

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
long double BFS::BreadFirstSearch(string start, string end, Airport airport){
    unordered_map<string, vector<pair<string,string>>> airport_adj_list = airport.getMap();
    // if (airport_adj_list.find(start) == airport_adj_list.end() || airport_adj_list.find(end) == airport_adj_list.end())
    // {
    //     cout<< " There are no routes from the input starting airport to the ending airport. Try again! " << endl;
    //     return -1;
    // }
    
    if (start == end) return 0;
    vector<pair<string,string>> vec = airport_adj_list[start];
    //vector<pair<string,string>> vec = airport.get_airport_adj(start);
    queue<string> q;
    q.push(start);
    long double count = 0;
    map<string, bool> visited;

    while (!q.empty())
    {
        string temp = q.front();
        q.pop();
        if (temp == start){
            count ++;
            start = airport_adj_list[temp].back().first;
        }
        for (size_t i = 0; i < airport_adj_list[temp].size(); i++)
        {
            if (airport_adj_list[temp].at(i).first == end)
            {
                return count;
            }
            else if (!visited[airport_adj_list[temp].at(i).first])
            {
                q.push(airport_adj_list[temp].at(i).first);
            }
            
            
        }
        visited[temp] = 1;
    }
   
    return -1;
}