#include "PathFinder.h"
#include <iostream>
#include <limits>

PathFinder::PathFinder(Graph& graph, const std::string& start, const std::string& end)
        : graph_(graph), start_(start), end_(end) {}

void PathFinder::dijkstra() {
    std::priority_queue<std::pair<int, std::string>, std::vector<std::pair<int, std::string>>, std::greater<>> pq;
    std::unordered_map<std::string, int> distances;
    std::unordered_map<std::string, std::string> previous;

    for (const auto& node : graph_.getNodes()) {
        distances[node] = std::numeric_limits<int>::max();
        previous[node] = "";
    }

    distances[start_] = 0;
    pq.push({0, start_});

    while (!pq.empty()) {
        auto [currentDistance, currentNode] = pq.top();
        pq.pop();

        if (currentDistance > distances[currentNode]) {
            continue;
        }

        const auto& neighbors = graph_.getAdjList().at(currentNode);
        for (const auto& [neighbor, weight, lineName] : neighbors) {
            int distance = currentDistance + weight;

            if (distance < distances[neighbor]) {
                distances[neighbor] = distance;
                previous[neighbor] = currentNode;
                pq.push({distance, neighbor});
            }
        }
    }

    distances_ = distances;
    previous_ = previous;
}


void PathFinder::findShortestPath() {
    dijkstra();

    for (std::string at = end_; at != ""; at = previous_[at]) {
        path_.push_back(at);
    }

    std::reverse(path_.begin(), path_.end());
}

void PathFinder::printPath() {
    if (path_.size() <= 1) {
        std::cout << "No path found or no line changes necessary from " << start_ << " to " << end_ << std::endl;
        return;
    }

    std::cout << "Path from " << start_ << " to " << end_ << ": ";
    std::string lastLine = "", currentLine;
    for (size_t i = 0; i < path_.size() - 1; ++i) {
        currentLine = graph_.getLine(path_[i], path_[i + 1]);
        if (i > 0 && currentLine != lastLine) {
            std::cout << "\nChange from line " << lastLine << " to " << currentLine << " at " << path_[i] << " -> "<< std::endl;
        }
        lastLine = currentLine;
        std::cout << path_[i] << " (" << lastLine << ") -> ";
    }
    std::cout << path_.back() << std::endl; // Print the last station
    std::cout << "Total cost: " << distances_[end_] << std::endl;
}


