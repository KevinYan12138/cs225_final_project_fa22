#pragma once
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>

#include "graph.h"
#include "edge.h"
#include "airport.h"

using namespace std;

class Dijkstra {
    public:
        /**
        * construct a weighted graph
        * @param airport - airport
        */
        Graph dataProcess(Airport airport);

        /**
        * return the shortest path from source to destination
        * @param airport - airport
        * @param source - the start airport
        * @param destination - the destination airport
        */
        vector<Vertex> dijkstraSSSP(Airport airport, Vertex source, Vertex destination);

    private:
        
};
