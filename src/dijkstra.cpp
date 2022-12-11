#include "dijkstra.h"

using namespace std;

long double INF = 0x3f3f3f3f;

vector<Vertex> Dijkstra::dijkstraSSSP(Graph g, Vertex source, Vertex destination) {
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

    for (unsigned long i = 0; i < vertices.size(); ++i) {
        distances[vertices[i]] = INF;
        previous[vertices[i]] = Vertex();
        visited[vertices[i]] = false;
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
        vector<Vertex> adjVertices = g.getAdjacent(u);
        
        pq.pop();
        for (Vertex v : adjVertices) {
            if (visited[v] == false) {
                int vidx;
                auto iter = find(adjVertices.begin(), adjVertices.end(), v);
                if (iter != adjVertices.end()) {
                    vidx = iter - adjVertices.begin();
                } else { break; }
                Vertex adj = adjVertices[vidx];
                int cost = g.getEdgeWeight(u, adj);
                if (cost + distances[u] < distances[v]) {
                    distances[v] = cost + distances[u];
                    //pq.push(make_pair(distances[adj], adj));
                    previous[v] = u;
                }
            }
        }
        visited[u] = true;
    }

    vector<Vertex> path;
    Vertex curr = destination;
    path.push_back(destination);

    while (curr != source) {
        path.push_back(previous[curr]);
        curr = previous[curr];
    }
    
    reverse(path.begin(), path.end());

    return path;
}
