#include "PathFinder.h"
#include <iostream>
#include <limits>

// Konstruktor der PathFinder-Klasse
PathFinder::PathFinder(Graph& graph, const std::string& start, const std::string& end)
        : graph_(graph), start_(start), end_(end) {}

// Implementierung des Dijkstra-Algorithmus
void PathFinder::dijkstra() {
     // Prioritätswarteschlange für Knoten, sortiert nach deren Distanzen
    std::priority_queue<std::pair<int, std::string>, std::vector<std::pair<int, std::string>>, std::greater<>> pq;
     
     // Initialisiere die Distanzen zu allen Knoten auf "unendlich" und die Vorgänger-Knoten auf leere Strings
    std::unordered_map<std::string, int> distances;
    std::unordered_map<std::string, std::string> previous;

    // Setze die Distanzen aller Knoten auf ein sehr großes Maximum

    for (const auto& node : graph_.getNodes()) {
        distances[node] = std::numeric_limits<int>::max();
        previous[node] = "";
    }
    // Setze die Distanz des Startknotens auf 0 und füge ihn in die Prioritätswarteschlange ein
    distances[start_] = 0;
    pq.push({0, start_});

    while (!pq.empty()) {
        auto [currentDistance, currentNode] = pq.top();// Hole den Knoten mit der kleinsten Distanz
        pq.pop();

        // Wenn die aktuelle Distanz größer als die gespeicherte Distanz ist, überspringe diesen Knoten
        if (currentDistance > distances[currentNode]) {
            continue;
        }
        // Hole die Nachbarn des aktuellen Knotens
        const auto& neighbors = graph_.getAdjList().at(currentNode);
        for (const auto& [neighbor, weight, lineName] : neighbors) {
            int distance = currentDistance + weight; // Berechne die neue Distanz

            // Wenn die neue Distanz kleiner ist, aktualisiere die Distanz und den Vorgänger
            if (distance < distances[neighbor]) {
                distances[neighbor] = distance;
                previous[neighbor] = currentNode;
                pq.push({distance, neighbor});// Füge den Nachbarknoten in die Prioritätswarteschlange ein
            }
        }
    }
    // Speichere die berechneten Distanzen und Vorgänger
    distances_ = distances;
    previous_ = previous;
}

// Findet den kürzesten Pfad von start_ nach end_

void PathFinder::findShortestPath() {
    dijkstra(); // Führe den Dijkstra-Algorithmus aus

    // Rekonstruiere den Pfad vom Endknoten zum Startknoten (in umgekehrter Reihenfolge)
    for (std::string at = end_; at != ""; at = previous_[at]) {
        path_.push_back(at);
    }
    // Drehe den Pfad um, um ihn vom Start- zum Endknoten darzustellen
    std::reverse(path_.begin(), path_.end());
}

// Gibt den gefundenen Pfad aus
void PathFinder::printPath() {
    if (path_.size() <= 1) {
        // Wenn der Pfad nicht gefunden wurde oder keine Linienwechsel notwendig sind
        std::cout << "No path found or no line changes necessary from " << start_ << " to " << end_ << std::endl;
        return;
    }
    // Ausgabe des Pfades
    std::cout << "Path from " << start_ << " to " << end_ << ": ";
    std::string lastLine = "", currentLine;
    for (size_t i = 0; i < path_.size() - 1; ++i) {
        currentLine = graph_.getLine(path_[i], path_[i + 1]);

        // Wenn sich die Linie ändert, gib eine Wechselmeldung aus
        if (i > 0 && currentLine != lastLine) {
            std::cout << "\nChange from line " << lastLine << " to " << currentLine << " at " << path_[i] << " -> "<< std::endl;
        }
        lastLine = currentLine;
        std::cout << path_[i] << " (" << lastLine << ") -> ";
    }
    // Ausgabe des letzten Knotens und der Gesamtkosten
    std::cout << path_.back() << std::endl; 
    std::cout << "Total cost: " << distances_[end_] << std::endl;
}


