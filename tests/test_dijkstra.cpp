#include <catch2/catch_test_macros.hpp>
#include "dijkstra.h"
#include <iostream>

using namespace std;

TEST_CASE("Dijkstra") {
    Airport airport;
    airport.read_airports_file("../airports.dat");
    airport.read_routes_file("../routes.dat");

    SECTION("Path exists") {
        Dijkstra dijkstra;
        Vertex source = "2965";
        Vertex destination = "2990";
        vector<Vertex> path = dijkstra.dijkstraSSSP(airport, source, destination);

        REQUIRE(path.size() > 1);
        REQUIRE(path[0] == "2965");
        REQUIRE(path[1] == "2990");
    }

    SECTION("No path exists") {
        Dijkstra dijkstra;
        Vertex source = "77";
        Vertex destination = "79";
        vector<Vertex> path = dijkstra.dijkstraSSSP(airport, source, destination);

        if (path.size() == 0) {
            cout << "No path exists.";
        }
    }

    SECTION("Path is the shortest 1") {
        Dijkstra dijkstra;
        Vertex source = "1";
        Vertex destination = "10";
        vector<Vertex> path = dijkstra.dijkstraSSSP(airport, source, destination);

        REQUIRE(path[0] == "1");
        REQUIRE(path[1] == "5");
        REQUIRE(path[2] == "3316");
        REQUIRE(path[3] == "1524");
        REQUIRE(path[4] == "492");
        REQUIRE(path[5] == "16");
        REQUIRE(path[6] == "8");
        REQUIRE(path[7] == "3995");
        REQUIRE(path[8] == "5448");
        REQUIRE(path[9] == "5446");
        REQUIRE(path[10] == "10");
    }

    SECTION("Path is the shortest 2") {
        Dijkstra dijkstra;
        Vertex source = "11";
        Vertex destination = "12";
        vector<Vertex> path = dijkstra.dijkstraSSSP(airport, source, destination);

        REQUIRE(path[0] == "11");
        REQUIRE(path[1] == "18");
        REQUIRE(path[2] == "12");
    }

}