#include <iostream>
#include "airport.h"
#include "cycle.h"
#include "dijkstra.h"
#include "bfs.h"

int main(){
    cout << "Hello World! This program can help you find the shortest path or cycles among aiports worldwide." << endl;
    string key;
    int indict = 0;
    Airport airport;
    airport.read_routes_file("../routes.dat");
    airport.read_airports_file("../airports.dat");

    while(indict == 0){
        cout << "Please type 1 if you want to find shortest path; type 2 for cycles; type 3 to exit program." << endl;
        getline(cin, key);
        if(key == "1"){
            cout << "Please enter the start airport name" << endl;
            string startAirport;
            string destAirport;
            getline(cin, startAirport);
            cout << "Please enter the destination airport name" << endl;
            getline(cin, destAirport);

            Dijkstra dijkstra;
            vector<Vertex> path = dijkstra.dijkstraSSSP(airport, airport.get_airportId(startAirport),  airport.get_airportId(destAirport));

            for (unsigned long i = 0; i < path.size(); i++) {
                if (i == path.size() - 1)
                    cout << airport.get_airportName(path[i]) << std::endl;
                else
                    cout << airport.get_airportName(path[i]) << " -> ";
            }

        }
        else if (key == "2"){
            string snum;
            cout << "Please enter the number of airports." << endl;
            getline(cin, snum);
            int num = stoi(snum);
            cycle cyc = cycle(num);
            string temp;
            vector<string> bookkeeping;
            for (int i = 0; i < (int)num; i++){
                getline(cin,temp);
                if(cyc.addAirport(bookkeeping,temp) == 2){
                    cyc.creat_list(airport, bookkeeping);
                    break;
                }
            }
            if(cyc.isCycle() == true){
                cout << "There is a cyle." << endl;
            }
            else{
                cout << "Cycle does not exist." << endl;
            }
        }
        else if (key == "3"){
            indict = 1;
        }
        else{
            cout << "Invalid number, please type again." << endl;
        }
    }
}
