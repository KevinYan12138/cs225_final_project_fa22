#include <catch2/catch_test_macros.hpp>
#include "airport.h"
#include <iostream>

using namespace std;


TEST_CASE("Test Airport Reader 1","[weight=1][part=1]") {
    Airport airport;
    airport.read_airports_file("../tests/test_airports.dat");

    pair<long double, long double> test1;
    test1.first = 145.391998291;
    test1.second = -6.081689834590001;

    pair<long double, long double> in1 = airport.get_location("1");
    
    REQUIRE(test1.first - in1.first < 0.001);
    REQUIRE(test1.second - in1.second < 0.001);

}

TEST_CASE("Test Airport Reader 2","[weight=1][part=1]") {
    Airport airport;
    airport.read_airports_file("../tests/test_airports.dat");

    pair<long double, long double> test2;
    test2.first = -81.2425;
    test2.second = 68.77610015869999;

    pair<long double, long double> in2 = airport.get_location("148");
    
    REQUIRE(test2.first - in2.first < 0.001);
    REQUIRE(test2.second - in2.second < 0.001);

}

TEST_CASE("Test Airport Reader 3","[weight=1][part=1]") {
    Airport airport;
    airport.read_airports_file("../tests/test_airports.dat");

    pair<long double, long double> test3;
    test3.first = 9.45244;
    test3.second = 24.292801;

    pair<long double, long double> in3 = airport.get_location("211");
    
    REQUIRE(test3.first - in3.first < 0.001);
    REQUIRE(test3.second - in3.second < 0.001);

}

TEST_CASE("Test Airport Reader 4","[weight=1][part=1]") {
    Airport airport;
    airport.read_airports_file("../tests/test_airports.dat");

    pair<long double, long double> test4;
    test4.first = -1.09582996368;
    test4.second = 51.616401672399995;

    pair<long double, long double> in4 = airport.get_location("555");
    
    REQUIRE(test4.first - in4.first < 0.001);
    REQUIRE(test4.second - in4.second < 0.001);

}

TEST_CASE("Test Airport Reader 5","[weight=1][part=1]") {
    Airport airport;
    airport.read_airports_file("../tests/test_airports.dat");

    pair<long double, long double> test5;
    test5.first = 2.7605500221;
    test5.second = 41.901000977;

    pair<long double, long double> in5 = airport.get_location("1222");
    
    REQUIRE(test5.first - in5.first < 0.001);
    REQUIRE(test5.second - in5.second < 0.001);

}

TEST_CASE("Test Airport Reader 6","[weight=1][part=1]") {
    Airport airport;
    airport.read_airports_file("../tests/test_airports.dat");

    pair<long double, long double> test6;
    test6.first = 149.610992432;
    test6.second = -32.5625;

    pair<long double, long double> in6 = airport.get_location("6808");
    
    REQUIRE(test6.first - in6.first < 0.001);
    REQUIRE(test6.second - in6.second < 0.001);

}

TEST_CASE("Test Airport Reader 7","[weight=1][part=1]") {
    Airport airport;
    airport.read_airports_file("../tests/test_airports.dat");

    pair<long double, long double> test7;
    test7.first = -72.27079772949219;
    test7.second = 42.898399353027344;

    pair<long double, long double> in7 = airport.get_location("8888");
    
    REQUIRE(test7.first - in7.first < 0.001);
    REQUIRE(test7.second - in7.second < 0.001);

}