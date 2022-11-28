#pragma once
#include <list>
#include <vector>
#include <unordered_map>
#include "airport.h"

class Cycle{
    public:
        Cycle();
        Cycle(unordered_map<string> edges);
        ~Cycle();
        bool isCycle();
        bool isSc();
        void DFS();
        
    private:
        int V;
        list<string> *adj;

}