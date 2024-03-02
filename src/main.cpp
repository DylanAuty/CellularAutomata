#include <iostream>
#include "CellularAutomaton.hpp"

const int GRID_H = 60;
const int GRID_W = 100;

int main(int, char**) {
    std::cout << "Hello, world!\n";
    CellularAutomaton gol_ca = CellularAutomaton(GRID_H, GRID_W);
    gol_ca.print_grid();

}
