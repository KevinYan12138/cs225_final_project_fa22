
#include <list>
#include <vector>
#include <unordered_map>
#include "airport.h"

class cycle{
    public:
        cycle();
        cycle(int V_);
        void creat_list(Airport ap_list, vector<string> edges);
        int addAirport(vector<string> &temp_list, string name);
        ~cycle();
        bool isCycle();
        bool isSc();
        void DFS(int v, vector<bool>&visited);
        cycle transpose();
        
    private:
        int V;      //the number of vertices
        Airport ap_list;        // Airport struct
        vector<vector<string>> adj;    //adjacency list for vertices 
        unordered_map<string, int> in_num;  // Number of input edges for each vertex
        unordered_map<string, int> index;   //Numbering index for each vertex 

};