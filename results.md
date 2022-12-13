# CS 225 Final Project Report (OpenFlights)

## Leading Question

Our final project uses the OpenFlights dataset containing airports, routes, etc. The leading question is how to find a short path between two airports, given any source and destination. Eventually we managed to address this goal. The main methods applied in this project are BST traversal of airports to find the path with the least layovers, Dijkstra's algorithm to find the shortest path between two airports, and Eulerian paths to find if there is a cycle in the graph to know if airports are connected to each other. We further developed test cases under the test folder independently to check whether each algorithm was implemented correctly.

## Data Acquisition

- For airports.dat, we create an unordered map called locations to store all corresponding latitude and longitude for each airport.
- For routes.dat, we create three unordered maps, one is our agency list for traversing the graph, and two for storing either the corresponding name for airport ID or the corresponding ID for airport name to convert from either one of those.
- Test: There are two files to test whether we have properly stored the data for the airport and route datasets respectively.

## Algorithms

### BFS

- Given a source airport and destination airport, we use a BFS in order to find the shortest route between them based on the least amount of connecting flights.
- Test: There are five test cases, one for testing whether BFS reads route file correctly, two for handling edge cases, and two for testing BFS traversal.
- Optimal runtime: $O(V + E)$

### Dijkstra's Algorithm

- The Graph, Edge and Random files contain the code to construct a weighted graph using the airports as the vertices.
- We use longitude and latitude coordinates of airports to calculate the distance between airports based on the haversine formula, set it as the weight of edges and calculate the route with the lowest cost from a source airport to the destination airport.
- Test: There are four test cases, which are all checked by hand. Two for testing if the path exists, and two for testing if the path is the shortest.
- Optimal runtime: $O(V + E \cdot log(V))$

### Cycle Detection

- We first check if the graph is strongly connected using ***Kosaraju’s algorithm***, and then check if the number of input edges is equal to the number of output edges for every vertex.
- Test: There are two test cases, which are both checked by hand. One is an Euler’s path and one is not.
- Optimal runtime: $O(V + E)$
