#ifndef TRAVELING_SALESMAN_H
#define TRAVELING_SALESMAN_H

#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

// Define struct for city
struct City {
    int id;
    vector<pair<int, double>> neighbors; // (neighbor, cost) pairs
    // Constructor
    City(int i) : id(i) {}
};

// Comparator for priority queue in UCS
struct UCSComparator {
    bool operator() (const pair<int, int>& a, const pair<int, int>& b) const {
        return a.second > b.second; // Sort by cost
    }
};

struct AStarComparator {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        // Sortăm în ordine crescătoare în funcție de suma costului până la nod și estimarea costului până la nodul țintă
        return a.second > b.second;
    }
};

bool UniformCostSearch(const vector<City>& cities, int start, int goal, vector<int>& path);
bool DFS(const vector<City>& cities, int current, unordered_set<int>& visited, vector<int>& path,int goal);
bool AStarSearch(const vector<City>& cities, int start, int goal, vector<int>& path);

#endif // TRAVELING_SALESMAN_H
