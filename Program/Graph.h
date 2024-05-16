#ifndef PROGRAM_GRAPH_H
#define PROGRAM_GRAPH_H
#include <iostream>


class Graph {
    public:
        void addEdge(const std::string& start, const std::string& end, int weight);
        void printGraph();
    private:
        std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> adjList;

};


#endif //PROGRAM_GRAPH_H
