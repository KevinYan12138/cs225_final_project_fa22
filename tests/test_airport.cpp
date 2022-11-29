#include <catch2/catch_test_macros.hpp>
#include "airport.h"
#include "airport.cpp"
#include <iostream>

using namespace std;


TEST_CASE("Test Airport Reader 1","[weight=1][part=1]") {
    //unordered_map<string, pair<long double, long double>> airports_list;
    Airport airport;
    airport.read_airports_file("airports.dat");

    pair<long double, long double> test1;
    test1.first = 145.391998291;
    test1.second = -6.081689834590001;
    
    REQUIRE(airport.get_location("1") == test1);

    //REQUIRE(airport.get_location("24") == pair<-56.083099365200006, 51.3918991089>);


}

// TEST_CASE("Test Airport Reader 2","[weight=1][part=1]") {
//     unordered_map<string, pair<long double, long double>> airports_list;
//     read_airports_file("airports.dat");

//     REQUIRE(airports_list["2423"].get_location() == pair<123.014999, 10.7764>);

//     REQUIRE(airports_list["2990"].get_location() == pair<49.278701782227, 55.606201171875>);
// }

// TEST_CASE("Test Airport Reader 3","[weight=1][part=1]") {
//     unordered_map<string, pair<long double, long double>> airports_list;
//     read_airports_file("airports.dat");

//     REQUIRE(airports_list["8888"].get_location() == pair<-72.27079772949219, 42.898399353027344>);

//     REQUIRE(airports_list["10952"].get_location() == pair<45.0125999451, 43.322299957300004>);
// }