
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
        int V;
        Airport ap_list;
        vector<vector<string>> adj;
        vector<string>temp_save;
        unordered_map<string, int> in_num;
        unordered_map<string, int> index;

};