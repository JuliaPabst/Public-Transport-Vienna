#include "Graph.h"
#include <queue>

void Graph::addEdge(const std::string& start, const std::string& end, int weight) {
    adjList[start].push_back(std::make_pair(end, weight));
    adjList[end].push_back(std::make_pair(start, weight));
}

void Graph::printGraph() {
    for (auto& node : adjList) {
        std::cout << "Station: " << node.first << " -> ";
        for (auto& edge : node.second) {
            std::cout << "(" << edge.first << ", " << edge.second << ") ";
        }
        std::cout << std::endl;
    }
}