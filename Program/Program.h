#ifndef PROGRAM_PROGRAM_H
#define PROGRAM_PROGRAM_H
#include <iostream>
#include <string>
#include "Graph.h"
#include "PathFinder.h"

class Program {
    public:
        Program();
        void runProgram();
    private:
        void readFileNameAndStations();
        void loadGraphFromFile();
        Graph graph_;
        std::vector<std::string> stations_;
        std::string fileName_;
};


#endif //PROGRAM_PROGRAM_H
