#include "airport.h"
#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include "bfs.h"
using namespace std;

TEST_CASE("Test BreadFirstSearch exceptions 1"){
    Airport airport;
    airport.read_routes_file("../tests/testroutes.dat");
    vector<string> vec;
    BFS bfs;
    cout << "traversal start with 0" << endl;
    vector<string> traversal = bfs.BreadFirstSearch("0",airport,vec);  
    for(size_t i =0; i < vec.size() ;i++){
        cout << vec[i] << endl;
    }
    cout << "" << endl;
    REQUIRE(traversal.empty());

}
TEST_CASE("Test BreadFirstSearch exceptions 2"){
    Airport airport;
    airport.read_routes_file("../tests/testroutes.dat");
    vector<string> vec;
    BFS bfs;
    cout << "traversal start with 1111" << endl;
    vector<string> traversal = bfs.BreadFirstSearch("1111",airport,vec);
    cout << "" << endl;
    for(size_t i =0; i < vec.size() ;i++){
        cout << vec[i] << endl;
    }
    REQUIRE(traversal.empty());

}
TEST_CASE("Test BreadFirstSearch 1"){
    Airport airport;
    airport.read_routes_file("../tests/testroutes.dat");
    airport.read_airports_file("../airports.dat");
    vector<string> vec;
    BFS bfs;
    vector<string> traversal = bfs.BreadFirstSearch("4029",airport,vec);
    cout << "traversal start with 4029" << endl;
    for(size_t i =0; i < traversal.size() ;i++){
        
        cout << traversal[i] << endl;
    }
    cout << "" << endl;
    REQUIRE(!traversal.empty());
    REQUIRE(traversal.size() == 3);
    REQUIRE(traversal.at(0)=="4029");
    REQUIRE(traversal.at(1)=="2990");
    REQUIRE(traversal.at(2)=="1111");
   
}
// TEST_CASE("Test BreadFirstSearch 2"){
//     Airport airport;
//     airport.read_routes_file("../tests/testroutes.dat");
//     vector<string> vec;
//     BFS bfs;
//     cout << "traversal start with 2968" << endl;
//     vector<string> traversal = bfs.BreadFirstSearch("2968",airport,vec);
   
//     for(size_t i =0; i < vec.size() ;i++){
       
//         cout << vec[i] << endl;
//     }
//     cout << "" << endl;
//     REQUIRE(!traversal.empty());
//     REQUIRE(traversal.size() == 4);
//     REQUIRE(traversal.at(0)=="2968");
//     REQUIRE(traversal.at(1)=="2990");
//     REQUIRE(traversal.at(2)=="4078");
//     REQUIRE(traversal.at(3)=="1111");
// }

