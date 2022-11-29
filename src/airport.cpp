#include <unordered_map>
#include <string>
#include <vector>
#include <cmath>
#include<sstream>
#include<iostream>
#include<bits/stdc++.h>

#include "airport.h"

using namespace std;


Airport::Airport() {}
Airport::~Airport() {}

long double Airport::calculate_dist(string start_airport, string dest_airport) {
    long double start_longitude = locations[start_airport].first;
    long double start_latitude = locations[start_airport].second;
    long double dest_longitude = locations[dest_airport].first;
    long double dest_latitude = locations[dest_airport].second;

    long double difflong = dest_longitude - start_longitude;
    long double difflat = dest_latitude - start_latitude;
 
    long double distance = pow(sin(difflat / 2), 2) + cos(start_latitude) * cos(dest_latitude) * pow(sin(difflong / 2), 2);
 
    distance = 2 * asin(sqrt(distance));
 
    long double r_of_earth = 6371;
     
    distance = distance * r_of_earth;

    return distance;
}

void Airport::insert_airport(string airport_name, long double longitude, long double latitude) {
    pair<long double, long double> location;
    location.first = longitude;
    location.second = latitude;
    locations[airport_name] = location;
}

void Airport::insert_route(string start_airport, string dest_airport, string airline) {
    pair<string, string> airlines;
    airlines.first = dest_airport;
    airlines.second = airline;

    airport_adj_list[start_airport].push_back(airlines);
}

void Airport::insert_airportName(string airportId, string airportName) {
    airportId_toName.insert(airportId, airportName);
}

void Airport::read_airports_file(string filename) {
    filename = "airports.dat";
    ifstream in(filename);

    string line;
    if (in.is_open()) {
        while(getline(in, line)) {
            stringstream s_stream(line);
            vector<string> words;

            while(s_stream.good()) {
                string substr;
                getline(s_stream, substr, ',');
                words.push_back(substr);
            }
            string airportId = words[0];
            string airportName = words[1];
            long double longitude = stold(words[7]);
            long double latitude = stold(words[6]);

            insert_airportName(airportId, airportName);

            if (airportId == "\N" || latitude == "\N" || longitude == "\N") {
            } else {
                insert_airport(airportId, longitude, latitude);
            }   
        }
    }
    in.close();
}

void Airport::read_routes_file(string filename) {
    filename = "airports.dat";
    ifstream in(filename);

    string line;
    if (in.is_open()) {
        while(getline(in, line)) {
            stringstream s_stream(line);
            vector<string> words;

            while(s_stream.good()) {
                string substr;
                getline(s_stream, substr, ',');
                words.push_back(substr);
            }
            string airlineId = words[1];
            string start_airportId = words[3];
            string dest_airportId = words[5];
            if (airlineId == "\N" || start_airportId == "\N" || dest_airportId == "\N") {
            } else {
                insert_airport(start_airportId, dest_airportId, airlineId);
            }   
        }
    }
    in.close();
}


pair<double, double> Airport::get_location(string airportId) {
    return locations[airportId];
}

vector<pair<string,string>> Airport::get_airport_adj(string airportId) {
    return airport_adj_list[airportId];
}

string Airport::get_airportName(string airportId) {
    return airportId_toName[airportId];
}