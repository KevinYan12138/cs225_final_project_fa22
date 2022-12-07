
#include <list>
#include <vector>
#include <unordered_map>
#include "airport.h"

class cycle{
    public:
        cycle(int V_);
        cycle(Airport ap_list, vector<string> edges);
        ~cycle();
        bool isCycle();
        bool isSc();
        void DFS(int v, vector<bool>&visited);
        cycle transpose();
        
    private:
        int V;
        vector<vector<string>> adj;
        unordered_map<string, int> in_num;
        unordered_map<string, int> index;
};