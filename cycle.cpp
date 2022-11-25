#include "cycle.h"

Cycle(){

}

Cycle(unordered_map<string> edges){
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

~Cycle(){

}



bool isCycle(){

}

bool isSc(){

}

void DFS(){

}