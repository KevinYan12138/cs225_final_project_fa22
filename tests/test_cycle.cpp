#include <catch2/catch_test_macros.hpp>
#include "airport.h"
#include "cycle.h"
#include <iostream>

using namespace std;

TEST_CASE("Test not Cycle 1","[weight=1][part=1]"){
    Airport airport;
    airport.read_airports_file("../airports.dat");
    airport.read_routes_file("../routes.dat");

    vector<string> temp;

    temp.push_back("Sochi International Airport");
    temp.push_back("Astrakhan Airport");
    temp.push_back("Chelyabinsk Balandino Airport");
    temp.push_back("Domodedovo International Airport");
    temp.push_back("Tolmachevo Airport");
    temp.push_back("Nizhnevartovsk Airport");
    temp.push_back("Kazan International Airport");
    temp.push_back("Khrabrovo Airport");
    temp.push_back("Heydar Aliyev International Airport");

    cycle cyc = cycle(9);
    cyc.creat_list(airport, temp);
    REQUIRE(cyc.isCycle() == false);
}

TEST_CASE("Test Cycle 2","[weight=1][part=1]"){
    Airport airport;
    airport.read_airports_file("../airports.dat");
    airport.read_routes_file("../routes.dat");

    vector<string> temp;

    temp.push_back("Sochi International Airport");
    temp.push_back("Kazan International Airport");

    cycle cyc = cycle(2);
    cyc.creat_list(airport, temp);
    REQUIRE(cyc.isCycle() == true);
}