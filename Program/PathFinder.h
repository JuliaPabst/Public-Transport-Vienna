#ifndef PROGRAM_PATHFINDER_H
#define PROGRAM_PATHFINDER_H

#include "Graph.h"
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

class PathFinder {
public:
    PathFinder(Graph& graph, const std::string& start, const std::string& end);
    void findShortestPath();
    void printPath();

private:
    Graph& graph_;
    std::string start_;
    std::string end_;
    std::unordered_map<std::string, int> distances_;
    std::unordered_map<std::string, std::string> previous_;
    std::vector<std::string> path_;

    void dijkstra();
};

#endif //PROGRAM_PATHFINDER_H
