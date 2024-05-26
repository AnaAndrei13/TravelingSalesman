#include"TravelingSalesman.h";
#include <iostream>

using namespace std;

int main() {

    // Define cities
    vector<City> cities;

    cities.push_back(City(0));
    cities.push_back(City(1));
    cities.push_back(City(2));
    cities.push_back(City(3));
    cities.push_back(City(4));
    cities.push_back(City(5));
    cities.push_back(City(6));
    cities.push_back(City(7));
    cities.push_back(City(8));
    cities.push_back(City(9));
    cities.push_back(City(10));
    cities.push_back(City(11));
    cities.push_back(City(12));
    cities.push_back(City(13));
    cities.push_back(City(14));
  

    int goal_city_id = 14;

    // Add neighbors and associated costs for each city
    cities[0].neighbors.push_back(make_pair(1, 10));
    cities[1].neighbors.push_back(make_pair(0, 10));
    cities[1].neighbors.push_back(make_pair(5, 15));
    cities[2].neighbors.push_back(make_pair(3, 15));
    cities[2].neighbors.push_back(make_pair(5, 7));
    cities[5].neighbors.push_back(make_pair(10, 7));
    cities[3].neighbors.push_back(make_pair(11, 10));
    cities[4].neighbors.push_back(make_pair(6, 10));
    cities[5].neighbors.push_back(make_pair(2, 15));
    cities[6].neighbors.push_back(make_pair(3, 15));
    cities[7].neighbors.push_back(make_pair(6, 7));
    cities[8].neighbors.push_back(make_pair(2, 7));
    cities[9].neighbors.push_back(make_pair(3, 10));
    cities[10].neighbors.push_back(make_pair(0, 10));
    cities[10].neighbors.push_back(make_pair(2, 15));
    cities[8].neighbors.push_back(make_pair(1, 15));
    cities[11].neighbors.push_back(make_pair(14, 7));
    cities[11].neighbors.push_back(make_pair(8, 7));
    cities[12].neighbors.push_back(make_pair(6, 15));
    cities[13].neighbors.push_back(make_pair(4, 7));
    cities[14].neighbors.push_back(make_pair(9, 7));
    // Define variables to store the minimum path
    vector<int> path;

    //Call the DFS function to explore possible solutions
    unordered_set<int> visited;
    visited.insert(0); // Mark the starting city as visited
    path.push_back(0); // Add the starting city to the minimum path

    bool found_path = DFS(cities, 0, visited, path, goal_city_id);

    //Checks if a path was found using DFS
    if (found_path) {
        // Shows the minimum used DFS path
        cout << "DFS Path: ";
        for (int city : path) {
            cout << city << " "; 
        }
        cout << endl;
    }
    else {
        cout << "No DFS path found!" << endl;
    }

    //UCS to find a better minimum cost path around the partial solution obtained using DFS
    
    path.clear(); // We clean up the least previously used DFS path
    found_path = UniformCostSearch(cities, 0, goal_city_id, path);

    // Checks if a path is found using UCS
    if (found_path) {
        //Shows the minimum UCS path used
        cout << "UCS Path: ";
        for (int city : path) {
            cout <<city << " ";
        }
        cout << endl;
    }
    else {
        cout << "No UCS path found!" << endl;
    }

    path.clear();
     found_path = AStarSearch(cities, 0, goal_city_id, path);

    //Checking if a road was found using A* Search
    if (found_path) {
        // Displaying the path found using A* Search
        cout << "Path A * : ";
        for (int city : path) {
            cout << city << " ";
        }
        cout << endl;
    }
    else {
        cout << "No A* path found!" << endl;
    }
	return 0;
}