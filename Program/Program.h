//
// Created by Julia Pabst on 16.05.24.
//

#ifndef PROGRAM_PROGRAM_H
#define PROGRAM_PROGRAM_H
#include <iostream>
#include <string>


class Program {
    public:
        void runProgram();

    private:
        void readStations();
        std::vector<std::string> stations_;
};


#endif //PROGRAM_PROGRAM_H
