#include "airport.h"
#include <catch2/catch_test_macros.hpp>
#include <iostream>

using namespace std;


TEST_CASE("Test file reading 1"){
    Airport airport;
    airport.read_routes_file("../tests/testroutes.dat");
    vector<pair<string,string>> vec1 = airport.get_airport_adj("2965");
    pair<string, string> test1;
    test1.first = "2990";
    test1.second = "410";
    REQUIRE(vec1[0] == test1);
}
TEST_CASE("Test file reading 2"){
    Airport airport;
    airport.read_routes_file("../tests/testroutes.dat");
    vector<pair<string,string>> vec2 = airport.get_airport_adj("2966");
    pair<string, string> test2;
    test2.first = "2990";
    test2.second = "410";
    REQUIRE(vec2[0] == test2);
}
TEST_CASE("Test file reading 3"){
    Airport airport;
    airport.read_routes_file("../tests/testroutes.dat");
    vector<pair<string,string>> vec3 = airport.get_airport_adj("2968");
    pair<string, string> test3;
    test3.first = "2990";
    test3.second = "410";
    REQUIRE(vec3[0] == test3);

    pair<string, string> test33;
    test33.first = "4078";
    test33.second = "410";
    REQUIRE(vec3[1] == test33);

}
TEST_CASE("Test file reading 4"){
    Airport airport;
    airport.read_routes_file("../tests/testroutes.dat");
    vector<pair<string,string>> vec4 = airport.get_airport_adj("4029");
    pair<string, string> test4;
    test4.first = "2990";
    test4.second = "410";
    REQUIRE(vec4[0] == test4);
}

// TEST_CASE("Test file reading 2" "FileR2"){
//     read_routes_file("testroutes.dat");
//     vector<pair<string,string>> vec2 = get_airport_adj("2966");
//     REQUIRES(airport_adj_list["2966"][0]) == <2990, 410>;
// }
// TEST_CASE("Test file reading 3" "FileR3"){
//     read_routes_file("testroutes.dat");
//     vector<pair<string,string>> vec3 = get_airport_adj("2968");
//     REQUIRES(airport_adj_list["2968"][0]) == <2990, 410>;
//     REQUIRES(airport_adj_list["2968"][1]) ==  <4078,410>;
    
// }
// TEST_CASE("Test file reading 4" "FileR4"){
//     read_routes_file("testroutes.dat");
//     vector<pair<string,string>> vec1 = get_airport_adj("4029");
//     REQUIRES(airport_adj_list["4029"]) == <2990, 410>;
// }