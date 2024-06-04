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


void Graph::addEdge(const std::string& start, const std::string& end, int weight) {
    // add edge (pair of destination station and weight) to start station in unordered map
    adjList[start].push_back(std::make_pair(end, weight));

    // add edge (pair of start station and weight) to destination station in unordered map
    adjList[end].push_back(std::make_pair(start, weight));
}


void Graph::printGraph() {
    // loop through all stations in the adjList
    for (auto& node : adjList) {
        // print the station name (key)
        std::cout << "Station: " << node.first << " -> ";
        // loop through all edges and print station name and cost
        for (auto& edge : node.second) {
            std::cout << "(" << edge.first << ", " << edge.second << ") ";
        }
        std::cout << std::endl;
    }
}
