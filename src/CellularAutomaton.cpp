#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include "CellularAutomaton.hpp"

CellularAutomaton::CellularAutomaton(int height, int width, int seed)
: _width(width), _height(height), _seed(seed), _udist(0, 1) {
	/**
	 * Constructor with seed.
	 * 
	 * @param height height of grid to generate.
	 * @param width width of grid to generate
	 * @param seed random seed to use.
	 */
	std::cout << "Cellular Automaton with width " << width << " and height " << height << std::endl;
	_rng.seed(_seed);

	_grid = std::vector<std::vector<bool>>(width, std::vector<bool>(height, false));
	_random_init_grid();
};

CellularAutomaton::CellularAutomaton(int height, int width)
: _width(width), _height(height), _udist(0, 1) {
	/**
	 * Constructor with seed.
	 * 
	 * @param height height of grid to generate.
	 * @param width width of grid to generate
	 * @param seed random seed to use.
	 */
	std::cout << "Cellular Automaton with width " << width << " and height " << height << std::endl;
	_seed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	_rng.seed(_seed);
	_grid = std::vector<std::vector<bool>>(width, std::vector<bool>(height, false));
	_random_init_grid();
};

void CellularAutomaton::_random_init_grid() {
	/** 
	 * Randomly initialises state of grid cells.
	 */
	for (int y = 0; y < _height; y++) {
		for (int x = 0; x < _width; x++) {
			_grid[x][y] = _udist(_rng);
		}
	}
}

void CellularAutomaton::print_grid() {
	/**
	 * Prints grid to stdout. Assumes 2 states only.
	 */
	char printchars[2] = {' ', '#'};
	for (int y = 0; y < _height; y++) {
		for (int x = 0; x < _width; x++) {
			std::cout << printchars[_grid[x][y]];
		}
		std::cout << std::endl;
	}
}