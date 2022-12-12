#include "cycle.h"
#include <algorithm>
using namespace std;

/*Description: Empty constructor of cycle, do nothing
Input: None
Output:None
side effect: creat a cycle class
*/
cycle::cycle(){

}
/*Description: Constructor to indicate the number of vertex 
Input: int V, the number of vertex
Output:None
side effect: creat a cycle class with V initialized
*/
cycle::cycle(int V_){
    V = V_;
}

/*Description: Destructor for cycle
Input: None
Output:None
side effect: destroy a cycle class
*/
cycle::~cycle(){

}

/*Description: Initialize the adjacency list and input num in cycle class
Input: ap_list is an already initialized Airport class which contains the 
       information for airports and routes.
        edges is a vector of string contaning the vertex of user input.
        User will input vertices onw by one but they will be stored in this 
        vector and passed in in a single time.
Output: None
side effect: Initialized the adacency list and input num in cycle. 
*/
void cycle::creat_list(Airport ap_list, vector<string> edges){
     V = edges.size();
     for(int i = 0; i < V; i++){
        vector<string> temp;
        adj.push_back(temp);
    }
    for(size_t counter = 0; counter < edges.size(); counter++){
        string target = edges[counter];
        index[target] = counter;
        adj[counter].push_back(target);
        string temp_id = ap_list.get_airportId(target);     //extract the vertex in the adjacency list of ap_list
        vector<pair<string,string>> temp = ap_list.get_airport_adj(temp_id);
        for(size_t j = 0; j < temp.size(); j++){
            string name = ap_list.get_airportName(temp[j].first);
            if(find(edges.begin(), edges.end(), name) != edges.end()){  //check if any element in edges is also in the adjacency list
                adj[counter].push_back(name);       //if exists, push back to the adjacency list in cycle
                in_num[name]++;                     //increase the input num of this vertex
            }
        }
    }
}

/*Description: Provided for user to add vertex one by one 
Input: temp_list is a vector of string to temporarily hold the 
       input vertex from user.
       name is the current input vertex name from user
Output: An int to indicate the current condition of input
side effect: None
*/
int cycle::addAirport(vector<string> &temp_list, string name){
    if((int)temp_list.size() == V){     //if user types more elements than indicated by V reture -1
        return -1;
    }
    temp_list.push_back(name);          
    if((int)temp_list.size() == V){     //If the size of the temp list is the same as V means that it is full and return2 to indicate.
        return 2;
    }
    return 1;                           //if it is not full, return 1
}


/*Description: Check if Euler's cycle exists or not
Input: None
Output: Bool to inidicate the answer
side effect: None
*/
bool cycle::isCycle(){

    if (!isSc()) return false;      //if the graph is not strongly connected, it will not be an Euler's path

    for (int i = 0; i < V; i++) {   //Check if for all vertices the input num is the same as teh output num
        if (adj[i].size()-1 != (unsigned long)in_num[adj[i][0]]) return false;
    }

    return true;
}


/*Description: Check if the graph is strongly connected or not
Input: None
Output: Bool to inidicate the answer
side effect: None
*/
bool cycle::isSc(){
    vector<bool> visited;   //vector to keep track the status of each vertex
    visited.reserve(V);

    for (int i = 0; i < V; i++) {
        visited.push_back(false);
    }
 
    int n;
    for (n = 0; n < V; n++) {   //Find the first vertex with neighbors to start
        if (adj[n].size()-1 > 0) break;
    }
    
    if(n == V){             //if n==V, means that the graph is not connected, so return false
        return false;
    }

    DFS(n, visited);    //Traverse through the graph
 
    for (int i = 0; i < V; i++) {
        if (adj[i].size()-1 > 0 && visited[i] == false) return false;   //If there is vertex not visited, teh graph is not connected
    }
 
    cycle cy = transpose();     //Transpose the  graph
 
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }
 
    cy.DFS(n, visited);     //Traverse as before
 
    for (int i = 0; i < V; i++) {
        if (cy.adj[i].size()-1 > 0 && visited[i] == false) return false;      //check for each vertex as before
    }
    return true;
}

/*Description: DFS to traverse through the graph
Input: None
Output: Bool to inidicate the answer
side effect: None
*/
void cycle::DFS(int v, vector<bool>&visited){
    visited[v] = true;                //mark vth vertex as visited
    for (size_t i = 1; i < adj[v].size(); ++i) {
        int indict = index[adj[v][i]];               //indict is the next vertex number 
        if (!visited[indict]) DFS(indict, visited);  //dfs through from indict  
    }
}


/*Description: Making all the output edge become input edge and vice versa
Input: None
Output: A transposed cycle
side effect: None
*/
cycle cycle::transpose() {
    cycle c = cycle();
    for(int i = 0; i < V; i++){
        vector<string> temp;
        c.adj.push_back(temp);
    }
    for (int v = 0; v < V; v++){
        for(auto i = adj[v].begin()+1; i != adj[v].end(); ++i){
            int indict = index[*i];
            c.adj[indict].push_back(adj[v][0]);           //reverse the input and output edges
            (c.in_num[adj[v][0]])++;                      //update input num for each vertex
        }
    }
    return c;
}