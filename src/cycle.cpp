#include "cycle.h"

Cycle::Cycle(){

}

Cycle::Cycle(unordered_map<string> edges){
    int counter = 0;
    for(auto it = edges.begin(); it != edges.end(); it++){
        adj[counter].push_back((*it));
        vector<pair<string,string>> temp = getList((*it));
        for(size_t j; j < temp.size(); j++){
            if(edges.find(temp[j].first) != edges.end()){
                adj[counter].push_back(temp[j].first);
            }
        }
        counter++;
    }

}

Cycle::~Cycle(){

}



bool Cycle::isCycle(){

    if (!isSc()) return false;

    for (int i = 0; i < V; i++) {
        if (adj[i].size() != in[i]) return false;
    }

    return true;
}

bool Cycle::isSc(){
    bool visited[V];

    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }
 
    int n;
    for (n = 0; n < V; n++) {
        if (adj[n].size() > 0) break;
    }
 
    DFS(n, visited);
 
    for (int i = 0; i < V; i++) {
        if (adj[i].size() > 0 && visited[i] == false) return false;
    }
 
    Cycle cy = transpose();
 
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }
 
    cy.DFS(n, visited);
 
    for (int i = 0; i < V; i++) {
        if (adj[i].size() > 0 && visited[i] == false) return false;
    }
    return true;
}

void Cycle::DFS(int v, bool visited[]){
    visited[v] = true;
    for (i = adj[v].begin(); i != adj[v].end(); ++i) {
        if (!visited[*i]) DFSUtil(*i, visited);
    }
}

Cycle Cycle::transpose() {
    Cycle c(V);
    for (int v = 0; v < V; v++){
        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i){
            c.adj[*i].push_back(v);
            (c.in[v])++;
        }
    }
    return c;
}