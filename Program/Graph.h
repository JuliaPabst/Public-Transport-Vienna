#ifndef PROGRAM_GRAPH_H
#define PROGRAM_GRAPH_H
#include <iostream>


class Graph {
    public:
        void addEdge(const std::string& start, const std::string& end, int weight);
        void printGraph();
    const std::unordered_map<std::string, std::vector<std::pair<std::string, int>>>& getAdjList() const { return adjList; }
    std::vector<std::string> getNodes() const;
    private:
        std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> adjList;
};


#endif //PROGRAM_GRAPH_H
