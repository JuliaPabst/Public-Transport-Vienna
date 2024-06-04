#ifndef PROGRAM_GRAPH_H
#define PROGRAM_GRAPH_H
#include <iostream>
#include <utility>
#include <unordered_map>


class Graph {
public:
    /*
        - reference because a copy is not needed (performance)
        - const because it should not be altered
    */
    void addEdge(const std::string &start, const std::string &end, int weight, const std::string &line);

    void printGraph();

    const std::unordered_map<std::string, std::vector<std::tuple<std::string, int, std::string>>>&
    getAdjList() const { return adjList; }
    std::string getLine(const std::string& from, const std::string& to);
    std::vector<std::string> getNodes() const;

private:
    /*
        # Choice of data type:
            -   unordered_map: stores several key and value pairs:
                key = station name (string)
                value = edges to other nodes (vector of pairs)
            -   tuple (has a fixed size and different data types):
                first element = station name of other station
                second element = cost between stations
                third element = line name
    */
    std::unordered_map<std::string, std::vector<std::tuple<std::string, int, std::string>>> adjList;
};

#endif //PROGRAM_GRAPH_H