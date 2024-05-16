#include "Graph.h"

void Graph::printGraph() {
    for (auto& node : adjList) {
        std::cout << "Station: " << node.first << " -> ";
        for (auto& edge : node.second) {
            std::cout << "(" << edge.first << ", " << edge.second << ") ";
        }
        std::cout << std::endl;
    }
}