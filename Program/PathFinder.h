#ifndef PROGRAM_PATHFINDER_H
#define PROGRAM_PATHFINDER_H

#include "Graph.h"
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>


// Die PathFinder-Klasse dient dazu, den kürzesten Pfad in einem Graphen zu finden
class PathFinder {
public:
    // Konstruktor: Initialisiert den PathFinder mit einem Graphen, einem Startknoten und einem Endknoten
    PathFinder(Graph& graph, const std::string& start, const std::string& end);
    // Findet den kürzesten Pfad von start_ nach end_
    void findShortestPath();
    // Gibt den gefundenen Pfad aus
    void printPath();

private:
    Graph& graph_;// Referenz auf den Graphen
    std::string start_; // Startknoten
    std::string end_; // Endknoten
    std::unordered_map<std::string, int> distances_;  // Distanzen der Knoten vom Startknoten
    std::unordered_map<std::string, std::string> previous_;// Vorgängerknoten für jeden Knoten im kürzesten Pfad
    std::vector<std::string> path_;// Der kürzeste Pfad als Liste von Knoten

    // Implementierung des Dijkstra-Algorithmus
    void dijkstra();
};

#endif //PROGRAM_PATHFINDER_H
