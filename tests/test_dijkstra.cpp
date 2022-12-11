#include <catch2/catch_test_macros.hpp>
#include "dijkstra.h"
#include <iostream>

using namespace std;

TEST_CASE("Dijkstra") {
    Airport airport;
    airport.read_airports_file("../tests/test_airports.dat");
    airport.read_routes_file("../tests/testroutes.dat");

    SECTION("Path exists") {
        Dijkstra dijkstra;
        cout << "1" << endl;
        Vertex source = "AER";
        Vertex destination = "KZN";
        vector<Vertex> path = dijkstra.dijkstraSSSP(airport, source, destination);
        cout << "2" << endl;

	for (unsigned long i = 0; i < path.size(); i++) {
		if (i == path.size() - 1)
			cout << path[i] << std::endl;
		else
			cout << path[i] << " -> ";
	}
        //REQUIRE(path.size() > 1);
        //REQUIRE(path[0] == "AER");
        //REQUIRE(path[1] == "KZN");
    }
/*
    SECTION("Path is the shortest") {
        vector<Vertex> path = dijkstraSSSP(airport, "AER", "KZN");
        REQUIRE(path[0] == "AER");
        REQUIRE(path[1] == "KZN");
        REQUIRE(path[2] == "KZN");
    }*/
}