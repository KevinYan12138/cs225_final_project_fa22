#include "airport.h"
#include "catch2/catch.hpp"
#include <iostream>

int print_out();

int print_out(){
    cout << "routes test start" << endl;
    return 0;
}

TEST_CASE("Test file reading 1" "FileR1"){
    read_routes_file("testroutes.dat");
    vector<pair<string,string>> vec1 = get_airport_adj("2965");
    REQUIRES(airport_adj_list["2965"][0]) == <2990, 410>;
}
TEST_CASE("Test file reading 2" "FileR2"){
    read_routes_file("testroutes.dat");
    vector<pair<string,string>> vec2 = get_airport_adj("2966");
    REQUIRES(airport_adj_list["2966"][0]) == <2990, 410>;
}
TEST_CASE("Test file reading 3" "FileR3"){
    read_routes_file("testroutes.dat");
    vector<pair<string,string>> vec3 = get_airport_adj("2968");
    REQUIRES(airport_adj_list["2968"][0]) == <2990, 410>;
    REQUIRES(airport_adj_list["2968"][1]) ==  <4078,410>;
    
}
TEST_CASE("Test file reading 4" "FileR4"){
    read_routes_file("testroutes.dat");
    vector<pair<string,string>> vec1 = get_airport_adj("4029");
    REQUIRES(airport_adj_list["4029"]) == <2990, 410>;
}