#include "dijkstra.h"
#include "airport.h"

using namespace std;

long double INF = 0x3f3f3f3f;

Graph Dijkstra::dataProcess(Airport airport) {
    Graph g(true);
    unordered_map<string, vector<pair<string,string>>> map = airport.getAdjList();
    for (const auto & [source, destAndAirline] : map) {
        //cout << key << ": " << value << endl;
        Vertex source_ = source;
        if (!g.vertexExists(source_)) {
            g.insertVertex(source_);
        }
        for (pair<string, string> i : destAndAirline) {
            Vertex dest = i.first;
            if (!g.vertexExists(dest)) {
                g.insertVertex(dest);
            }

            if (!g.edgeExists(source_, dest)) {
                g.insertEdge(source_, dest);
                long double dis = airport.calculate_dist(source, i.first);
                g.setEdgeWeight(source_, dest, dis);
            }
        }
    }
    return g;
}

vector<Vertex> Dijkstra::dijkstraSSSP(Airport airport, Vertex source, Vertex destination) {
    Graph g = dataProcess(airport);
    vector<Vertex> vertices = g.getVertices();

    // map of distance for each vertex
    unordered_map<Vertex, double> distances;
    
    // map current vertex to its previous vertex
    unordered_map<Vertex, Vertex> previous;

    // min distance of all vertices order by distance
    struct Compare {
        bool operator() (pair<Vertex, double> const& a, pair<Vertex, double> const& b) {
            return a.second > b.second;
        }
    };
    priority_queue<pair<Vertex, double>, vector<pair<Vertex, double>>, Compare> pq;
    pq.push(make_pair(source, 0));
    
    // labeled set
    unordered_map<Vertex, bool> visited;

    for (unsigned long i = 0; i < vertices.size(); ++i) {
        distances[vertices[i]] = INF;
        previous[vertices[i]] = Vertex();
        visited[vertices[i]] = false;
    }
    distances[source] = 0.0;

    int i = 0;
    cout << i;
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
        cout << i;
        Vertex u = pq.top().first;
        vector<Vertex> adjVertices = g.getAdjacent(u);
        
        pq.pop();
        for (Vertex v : adjVertices) {
            if (visited[v] == false) {
                double cost = g.getEdgeWeight(u, v);
                if (cost + distances[u] < distances[v]) {
                    distances[v] = cost + distances[u];
                    pq.push(make_pair(v, distances[v]));
                    previous[v] = u;
                }
            }
        }
        visited[u] = true;

        // if(pq.empty()){
        //     break;
        // }
        i++;
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
