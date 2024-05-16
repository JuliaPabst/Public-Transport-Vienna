#include "Program.h"

void Program::runProgram(){
    readStations();
}

void Program::readStations(){
    std::cout << "Enter your start station!" << std::endl;
    std::cin >> stations_[0];
    std::cout << " " << std::endl;

    std::cout << "Enter your destination station!" << std::endl;
    std::cin >> stations_[1];

}
