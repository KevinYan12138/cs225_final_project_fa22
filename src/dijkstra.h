#pragma once
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>

#include "graph.h"
#include "edge.h"

using namespace std;

class Dijkstra {
    public:
        //Dijkstra();
        //~Dijkstra();
        vector<Vertex> dijkstraSSSP(Graph g, Vertex source, Vertex destination);

    private:
        
};
