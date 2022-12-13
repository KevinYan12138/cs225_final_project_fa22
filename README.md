# CS225 Final Project -- Flights Checker

## Team members: 
- Victor Li  
- Kevin Yan
- Nick Gong
- Nicole Miao

## Project Descriptions: 	
Flights Checker will takes in the airports and routes dataset, clean and store the data("Airport.h", "Airport.cpp"). The Breadth First Search Algorithm can  traverse the airports given a starting airport("bfs.h", "bfs.cpp"). To find the shortest path from the starting airport to the destination airport we used Dijkstra's Algorithm("dijkstra.h", "dijkstra.cpp"). Next, through implementing the Kosaraju's algorithm we can find if there are Euler's path in the graph("cycle.h", "cycle.cpp"). In the main function, we created a user interface that can interact with the users of Flights Checker("main.cpp").

## Datasets used:
- "airports.dat" and "routes.dat" files from https://openflights.org/data.html

## Organization of the repository:
- /entry/main.cpp : user interface of the program
- /src : The folder for algorithms we implemented
  - "airport.h" and "airport.cpp" : Data acquisition
  - "bfs.h" and "bfs.cpp" : Breadth First Search algorithm
  - "cycle.h" and "cycle.cpp" : Find Euler's path using Kosaraju's algorithm
  - "dijkstra.h" and "dijkstra.cpp" : Dijkstra's algorithm
  - "edge.h", "graph.h", "graph.cpp", "random.h" and "random.hpp" : Some helper functions for Dijkstra's algorithm
- /tests : The folder for testcases
  - "test_airports.dat" and "testroutes.dat" : Smaller datasets for testing
  - "test_airport.cpp" and "test_routes.cpp" : Testcases for data acquisition
  - "test_bfs.cpp" : Testcases for Breadth First Search algorithm
  - "test_cycle.cpp" : Testcases for Euler's path detection
  - "test_dijkstra.cpp" : Testcases for Dijkstra's algorithm
 
## Running the program:

