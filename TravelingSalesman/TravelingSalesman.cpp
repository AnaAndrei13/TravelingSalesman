#include "TravelingSalesman.h"

// Exhaustive strategies
   // 1.Depth-First Search 
bool DFS(const vector<City>& cities, int current, unordered_set<int>& visited, vector<int>& path,int goal) {
    if (current == goal) {
        return true;
    }
    for (const auto& neighbor_pair : cities[current].neighbors) {
        int neighbor = neighbor_pair.first;
        if (visited.find(neighbor) == visited.end()) {
            visited.insert(neighbor);
            path.push_back(neighbor);
            if (DFS(cities, neighbor, visited, path,goal)) {
                return true;
            }
            path.pop_back();
            visited.erase(neighbor);
        }
    }
    return false;
}

  // 2.Uniform Cost Search 
bool UniformCostSearch(const vector<City>& cities, int start, int goal, vector<int>& path) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, UCSComparator> frontier;
    unordered_set<int> explored;
    vector<int> parent(cities.size(), -1); // Vector to track the parent of each node in the path
    frontier.push({ start, 0 }); // (node, cost)
    while (!frontier.empty()) {
        int node = frontier.top().first;
        int cost = frontier.top().second;
        frontier.pop();
        if (node == goal) {
            // Reconstruct path
            int current = node;
            while (current != start) {
                path.push_back(current);
                current = parent[current];
            }
            path.push_back(start);
            reverse(path.begin(), path.end()); // Reverse path pentru a o afișa de la start la goal
            return true; // Found goal
        }
        if (explored.find(node) == explored.end()) {
            explored.insert(node);
            for (const auto& neighbor : cities[node].neighbors) {
                int neighbor_id = neighbor.first;
                int neighbor_cost = neighbor.second;
                if (explored.find(neighbor_id) == explored.end()) {
                    frontier.push({ neighbor_id, cost + neighbor_cost });
                    // We set the parent of the neighbor node to rebuild the path later
                    parent[neighbor_id] = node;
                }
            }
        }
    }
    return false; // Goal not found
}
//Heuristic strategy

int heuristic(const City& city, int goal) {
    return abs(city.id - goal);
}
bool AStarSearch(const vector<City>& cities, int start, int goal, vector<int>& path) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, AStarComparator> frontier;
    unordered_set<int> explored;
    vector<int> parent(cities.size(), -1); // Vector to track the parent of each node in the path
    frontier.push({ start, 0 }); // (node, f_cost)
    while (!frontier.empty()) {
        int node = frontier.top().first;
        frontier.pop();
        if (node == goal) {
            // Reconstruct path
            int current = node;
            while (current != start) {
                path.push_back(current);
                current = parent[current];
            }
            path.push_back(start);
            reverse(path.begin(), path.end()); // Reverse path pentru a o afișa de la start la goal
            return true; // Found goal
        }
        if (explored.find(node) == explored.end()) {
            explored.insert(node);
            for (const auto& neighbor : cities[node].neighbors) {
                int neighbor_id = neighbor.first;
                int neighbor_cost = neighbor.second;
                if (explored.find(neighbor_id) == explored.end()) {
                    int f_cost = neighbor_cost + heuristic(cities[neighbor_id], goal);
                    frontier.push({ neighbor_id, f_cost });
                    // We set the parent of the neighbor node to rebuild the path later
                    parent[neighbor_id] = node;
                }
            }
        }
    }
    return false; // Goal not found
}