#include "Graph.h"
#include <queue>


std::vector<std::string> Graph::getNodes() const {
    std::vector<std::string> nodes;

    /*
        - loop through every element in the adjList
        - add the name (key/first element) of the station at the back of the nodes vector
     */
    for (const auto& pair : adjList) {
        nodes.push_back(pair.first);
    }
    return nodes;
}

std::string Graph::getLine(const std::string& from, const std::string& to) {
    // checks if specific key (from) exists in unordered_map
    if (adjList.find(from) != adjList.end()) {
        for (const auto& edge : adjList[from]) {
            if (std::get<0>(edge) == to) { // std::get<0>(edge) is the destination station
                return std::get<2>(edge);  // std::get<2>(edge) is the line name
            }
        }
    }
    return "";  // Return empty if no direct connection or station doesn't exist
}


void Graph::addEdge(const std::string& start, const std::string& end, int weight, const std::string& line) {
    // add edge (pair of destination station, weight and line name) to start station in unordered map
    adjList[start].push_back(std::make_tuple(end, weight, line));
    // add edge (pair of start station, weight and line name) to destination station in unordered map
    adjList[end].push_back(std::make_tuple(start, weight, line)); // Assuming undirected graph for simplicity
}





void Graph::printGraph() {
    // loop through all stations in the adjList
    for (auto& node : adjList) {
        // print the station name (key)
        std::cout << "Station: " << node.first << " -> ";
        // Loop through all edges and print station name, cost, and line name
        for (const auto& edge : node.second) {
            std::cout << "(" << std::get<0>(edge) << ", " << std::get<1>(edge) << ", " << std::get<2>(edge) << ") ";
        }
        std::cout << std::endl;
    }
}
