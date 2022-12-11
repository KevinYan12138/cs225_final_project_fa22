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
        /**
        * return the shortest path from source to destination
        * @param g - graph
        * @param source - the start airport
        * @param destination - the destination airport
        */
        vector<Vertex> dijkstraSSSP(Graph g, Vertex source, Vertex destination);

    private:
        
};
