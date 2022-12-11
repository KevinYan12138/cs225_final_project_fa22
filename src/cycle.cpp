#include "cycle.h"
#include <algorithm>
using namespace std;

/*Description: Empty constructor of cycle, do nothing
Input: None
Output:None
side effect: creat a cycle class
*/
cycle::cycle(){

}

cycle::cycle(int V_){
    V = V_;
}

cycle::~cycle(){

}

void cycle::creat_list(Airport ap_list, vector<string> edges){
     V = edges.size();
     for(int i = 0; i < V; i++){
        vector<string> temp;
        adj.push_back(temp);
    }
    for(size_t counter = 0; counter < edges.size(); counter++){
        string target = edges[counter];
        index[target] = counter;
        adj[counter].push_back(target);
        string temp_id = ap_list.get_airportId(target);
        vector<pair<string,string>> temp = ap_list.get_airport_adj(temp_id);
        for(size_t j = 0; j < temp.size(); j++){
            string name = ap_list.get_airportName(temp[j].first);
            if(find(edges.begin(), edges.end(), name) != edges.end()){
                adj[counter].push_back(name);
                in_num[name]++;
            }
        }
    }
}


int cycle::addAirport(vector<string> &temp_list, string name){
    if((int)temp_list.size() == V){
        return -1;
    }
    temp_list.push_back(name);
    if((int)temp_list.size() == V){
        return 2;
    }
    return 1;
}



bool cycle::isCycle(){

    if (!isSc()) return false;

    for (int i = 0; i < V; i++) {
        if (adj[i].size()-1 != (unsigned long)in_num[adj[i][0]]) return false;
    }

    return true;
}

bool cycle::isSc(){
    vector<bool> visited;
    visited.reserve(V);

    for (int i = 0; i < V; i++) {
        visited.push_back(false);
    }
 
    int n;
    for (n = 0; n < V; n++) {
        if (adj[n].size()-1 > 0) break;
    }
    
    if(n == V){
        return false;
    }

    DFS(n, visited);
 
    for (int i = 0; i < V; i++) {
        if (adj[i].size()-1 > 0 && visited[i] == false) return false;
    }
 
    cycle cy = transpose();
 
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }
 
    cy.DFS(n, visited);
 
    for (int i = 0; i < V; i++) {
        if (cy.adj[i].size()-1 > 0 && visited[i] == false) return false;
    }
    return true;
}

void cycle::DFS(int v, vector<bool>&visited){
    visited[v] = true;
    for (size_t i = 1; i < adj.size(); ++i) {
        if (!visited[i]) DFS(i, visited);
    }
}

cycle cycle::transpose() {
    cycle c = cycle();
    for(int i = 0; i < V; i++){
        vector<string> temp;
        c.adj.push_back(temp);
    }
    for (int v = 0; v < V; v++){
        for(auto i = adj[v].begin()+1; i != adj[v].end(); ++i){
            int indict = index[*i];
            c.adj[indict].push_back(adj[v][0]);
            (c.in_num[adj[v][0]])++;
        }
    }
    return c;
}