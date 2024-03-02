#include <iostream>
#include <chrono>
#include <thread>
#include "CellularAutomaton.hpp"

const int GRID_H = 50;
const int GRID_W = 200;

int main(int, char**) {
    std::cout << "Hello, world!\n";
    CellularAutomaton gol_ca = CellularAutomaton(GRID_H, GRID_W);
    while(1) {
        gol_ca.print_grid();
        gol_ca.step();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}
