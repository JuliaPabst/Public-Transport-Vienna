#include "Program.h"
#include <fstream>
#include <sstream>

Program::Program(){
    // size 2 for start and destination station
    stations_.resize(2);
}

void Program::runProgram() {
    readFileNameAndStations();
    loadGraphFromFile();
    // graph_.printGraph();
    PathFinder pathFinder(graph_, stations_[0], stations_[1]);
    pathFinder.findShortestPath();
    pathFinder.printPath();
}

void Program::readFileNameAndStations(){
    std::cout << "Enter the name of the file you want to analyse!" << std::endl;
    std::cin >> fileName_;
    std::cout << " " << std::endl;

    std::cout << "Enter your start station!" << std::endl;
    std::cin >> stations_[0];
    std::cout << " " << std::endl;

    std::cout << "Enter your destination station!" << std::endl;
    std::cin >> stations_[1];
}

void Program::loadGraphFromFile() {
    std::ifstream file(fileName_);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << fileName_ << std::endl;
        return;
    }

    std::string line;
    while (getline(file, line)) {
        std::istringstream iss(line);
        std::string lineName;
        // read until colon and ignores it
        getline(iss, lineName, ':');

        std::string station;
        std::string lastStation;
        int cost;


        // go from station to station
        while (iss >> std::quoted(station) >> cost) {
            if (!lastStation.empty()) {
                graph_.addEdge(lastStation, station, cost, lineName);
            }
            lastStation = station;
        }
    }
    file.close();
}
