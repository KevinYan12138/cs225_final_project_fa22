#include <catch2/catch_test_macros.hpp>
#include "airport.h"
#include "cycle.h"
#include <iostream>

using namespace std;

int SplitString(const std::string & str1, char sep, std::vector<std::string> &fields) {
    std::string str = str1;
    std::string::size_type pos;
    while((pos=str.find(sep)) != std::string::npos) {
        fields.push_back(str.substr(0,pos));
        str.erase(0,pos+1);  
    }
    fields.push_back(str);
    return fields.size();
}

TEST_CASE("Test small Cycle 1","[weight=1][part=1]"){
    Airport airport;
    airport.read_airports_file("../airports.dat");
    airport.read_routes_file("../routes.dat");

    cycle cyc = cycle();

    // ifstream f("../airports.dat");
    // string line;
    // int count;
    // while(getline(f,line) && count <= 20){
    //     int r = rand() % 2;
    //     vector<string>temp;
    //     SplitString(line, ',', temp);
    //     if(r == 0){
    //         cyc.addAirport(temp[0]);
    //     }
    //     count++;
    // }
    cyc.addAirport(airport,"2965");
    cyc.addAirport(airport,"2966");
    cyc.addAirport(airport,"2968");
    cyc.addAirport(airport,"4029");
    cyc.addAirport(airport,"2990");
    cyc.addAirport(airport,"4078");
    cyc.addAirport(airport,"2922");
    cyc.addAirport(airport,"2952");
    cyc.addAirport(airport,"6969");
    cyc.addAirport(airport,"2972");

    REQUIRE(cyc.isCycle() == false);
}