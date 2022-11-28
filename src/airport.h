#pragma once
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Airport{
    public:
        Airport();
        ~Airport();
        long double calculate_dist(string start_airport, string dest_airport);
        void insert_airport(string airport_name, long double longitude, long double latitude);
        void insert_route(string start_airport, string dest_airport, string airline);
        void insert_airportName(string airportId, string airportName);
        
        void read_airports_file(string filename);
        void read_routes_file(string filename);

        pair<double, double> get_location(string airportId);
        vector<pair<string,string>> get_airport_adj(string airportId);
        string get_airportName(string airportId);

        

    private:
        unordered_map<string, pair<long double, long double>> locations;
        /*key:unordered map of the start airport id. vector: destination airport id and corresponding airline.*/
        unordered_map<string, vector<pair<string,string>>> airport_adj_list; 

        unordered_map<string, string> airportId_toName; 

};