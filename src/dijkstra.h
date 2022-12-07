#pragma once
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>

#include "graph.h"

using namespace std;

class Dijkstra {
    public:
        Dijkstra();
        ~Dijkstra();
        vector<Vertex> dijkstraSSSP(Graph<Vertex> g, Vertex source, Vertex destination);

    private:
        
};
