#include "cycle.h"
#include <algorithm>
using namespace std;

cycle::cycle(int V_){
    this->V = V_;
    vector<vector<string>> out;
    for(int i = 0; i < V_; i++){
        vector<string> temp;
        temp.reserve(V_);
        out.push_back(temp);
    }
}

cycle::cycle(Airport ap_list, vector<string> edges){
    adj.reserve(edges.size());
    for(size_t counter = 0; counter < edges.size(); counter++){
        string target = edges[counter];
        index[target] = counter;
        adj[counter].push_back(target);
        vector<pair<string,string>> temp = ap_list.get_airport_adj(target);
        for(size_t j = 0; j < temp.size(); j++){
            if(find(edges.begin(), edges.end(), temp[j].first) != edges.end()){
                adj[counter].push_back(temp[j].first);
                in_num[temp[j].first]++;
            }
        }
    }
}

cycle::~cycle(){

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
        visited[i] = false;
    }
 
    int n;
    for (n = 0; n < V; n++) {
        if (adj[n].size()-1 > 0) break;
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
        if (adj[i].size()-1 > 0 && visited[i] == false) return false;
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
    cycle c(V);
    for (int v = 0; v < V; v++){
        list<int>::iterator i;
        for(auto i = adj[v].begin()+1; i != adj[v].end(); ++i){
            int indict = index[*i];
            c.adj[indict].push_back(adj[v][0]);
            (c.in_num[adj[v][0]])++;
        }
    }
    return c;
}