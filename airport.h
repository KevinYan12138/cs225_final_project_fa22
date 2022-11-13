#pragma once
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Airport{
    public:
        Airport();
        ~Airport();
        long calculate_dist(string start_airport, string dest_airport);
        void insert_airport(string airport_name, long longitude, long latitude);
        void insert_route(string start_airport, string dest_airport, string airline);
        

    private:
        unordered_map<string, pair<long, long>> locations;
        /*key:unordered map of the start airport id. vector: destination airport id and corresponding airline.*/
        unordered_map<string, vector<pair<string,string>>> airport_adj_list; 

}