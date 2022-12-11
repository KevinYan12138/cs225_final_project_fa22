#include <iostream>
#include "airport.h"
#include "cycle.h"
#include "dijkstra.h"
#include "bfs.h"

int main(){
    cout << "Hello World! This program can help you find the shortest path or cycles among aiports worldwide." << endl;
    int key;
    int indict = 0;
    Airport airport;
    airport.read_routes_file("../routes.dat");
    airport.read_airports_file("../aiports.dat");


    while(indict == 0){
        cout << "Please type 1 if you want to find shortest path; type 2 for cycles; type 3 to exit program." << endl;
        cin >> key;
        if(key == 1){
            cout << "Please enter the start airport name" << endl;
            string name1;
            string name2;
            cin >> name1;
            cout << "Please enter the destination airport name" << endl;
            cin >> name2;


        }
        else if (key == 2){
            int num;
            cout << "Please enter the number of airports." << endl;
            cin >> num;
            cycle cyc = cycle(num);
            string temp;
            vector<string> bookkeeping;
            for (int i = 0; i < num; i++){
                cin >> temp;
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
        else if (key == 3){
            indict = 1;
        }
        else{
            cout << "Invalid number, please type again." << endl;
        }
    }
}