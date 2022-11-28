#include "dijkstra.h"

using namespace std;

long double INF = 0x3f3f3f3f;

/*
DijkstraSSSP(G, s) {
    foreach (Vertex v : G) {
        d[v] = +inf
        p[v] = NULL
    }
    d[s] = 0
    
    PriorityQueue Q // min distance, defined by d[v]
    Q.buildHeap(G.vertices())
    Graph T // "labeled set"
    
    repeat n times {
        Vertex u = Q.removeMin()
        T.add(u)
        foreach (Vertex v : neighbors of u not in T) {
            if cost(u, v) + d[u] < d[v] {
                d[v] = cost(u, v) + d[u]
                p[v] = u
            }
        }
    }
}
*/

Dijkstra() {}
~Dijkstra() {}

vector<Vertex> Dijkstra::dijkstraSSSP(Graph<Vertex> g, Vertex source, Vertex destination) {
    vector<Vertex> vertices = g.getVertices();

    // map of distance for each vertex
    unordered_map<Vertex, double> distances;
    
    // map current vertex to its previous vertex
    unordered_map<Vertex, Vertex> previous;

    // min distance of all vertices order by distance
    priority_queue<pair<Vertex, double>, vector<pair<Vertex, double>>, greater<pair<Vertex, double>>> pq;
    pq.push(make_pair(source, 0));
    
    // labeled set
    unordered_map<Vertex, bool> visited;

    for (auto v = 0; v < vertices.size(); ++v) {
        distances[vertices[i]] = INF;
        previous[vertices[i]] = Vertex();
        visited[vertices[v]] = false;
    }
    distances[source] = 0.0;

    while (pq.top().first != destination) {
        /*
        long double min = INF;
        for (int i = 0; i < distances.size(); i++) {
            if (visited[i] == false) {
                if (min > distances[i]) {
                    min = distances[i];
                    minIdx = i;
                }
            }
        }
        Vertex u = vertices[minIdx];
        visited[minIdx] = true;
        */
        Vertex u = pq.top().first;
        pq.pop();
        for (Vertex v : g.getAdjacent(u)) {
            if (visited[v] == false) {
                Vertex adj = g.getAdjacent(u)[v];
                int cost = g.getEdgeWeight(u, adj);
                if (cost + distances[u] < distances[adj]) {
                    distances[adj] = cost + distances[u];
                    pq.push(make_pair(distances[adj], adj));
                    previous[adj] = u;
                }
            }
        }
        visited[u] = true;
    }

    Vertex curr = destination;
    path.push_back(destination);

    while (curr != source) {
        path.push_back(previous[curr]);
        curr = previous[curr];
    }
    
    reverse(path.begin(), path.end());

    return path;
}
