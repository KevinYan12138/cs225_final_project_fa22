#pragma once
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Airport{
    public:
        Airport();
        ~Airport();

        // calculate distance between two airports using latitude and longitude
        long double calculate_dist(string start_airport, string dest_airport); 

        // put airport data into locations
        void insert_airport(string airport_name, long double longitude, long double latitude); 

        // put airline route into adj list
        void insert_route(string start_airport, string dest_airport, string airline); 

        // put corresponding airportId and name into maps
        void insert_airportName(string airportId, string airportName); 
        
        // read airport.dat
        void read_airports_file(string filename); 

        //read route.dat
        void read_routes_file(string filename);

        // get latitude and longitude
        pair<long double, long double> get_location(string airportId);

        // get vector of destination airport id and corresponding airline.
        vector<pair<string,string>> get_airport_adj(string airportId);

        // convert airportId to name
        string get_airportName(string airportId); 

        // convert name to airportId
        string get_airportId(string airportName); 

        // get adj list
        unordered_map<string, vector<pair<string,string>>> getAdjList();
        

    private:
        /**
         *key: airportId 
         *value: latitude and longitude
        */
        unordered_map<string, pair<long double, long double>> locations;
        
        /**
         *key: start airport id 
         *value: vector of destination airport id and corresponding airline
        */
        unordered_map<string, vector<pair<string,string>>> airport_adj_list; 

        /**
         *key: airport id 
         *value: airport name
        */
        unordered_map<string, string> airportId_toName; 

        /**
         *key: airport name 
         *value: airport id
        */
        unordered_map<string, string> airportName_toId; 

};