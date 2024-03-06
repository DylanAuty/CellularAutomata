#include <iostream>
#include <vector>
#include <random>
#include <map>
#include <chrono>
#include "CellularAutomaton.hpp"

CellularAutomaton::CellularAutomaton(int height, int width, int seed)
: _width(width), _height(height), _seed(seed), _bdist(0.2) {
	std::cout << "Cellular Automaton with width " << width << " and height " << height << std::endl;
	_rng.seed(_seed);

	_grid = std::vector<std::vector<int>>(width, std::vector<int>(height, 0));
	_num_neighbours_grid = std::vector<std::vector<int>>(width, std::vector<int>(height, 0));
	_init_transition_table();
	_random_init_grid();
};


CellularAutomaton::CellularAutomaton(int height, int width)
: _width(width), _height(height), _bdist(0.2) {
	std::cout << "Cellular Automaton with width " << width << " and height " << height << std::endl;
	_seed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	_rng.seed(_seed);
	_grid = std::vector<std::vector<int>>(width, std::vector<int>(height, 0));
	_num_neighbours_grid = std::vector<std::vector<int>>(width, std::vector<int>(height, 0));
	_init_transition_table();
	_random_init_grid();
};


void CellularAutomaton::_init_transition_table() {
	int NUM_STATES = 2;
	// Initialise each state to die always regardless of number of neighbours
	for (int i = 0; i < NUM_STATES; i++) {
		for (int j = 0; j < 8; j++) {
			_transition_table[i][j] = 0;
		}
	}
	// Override the relevant items with hardcoded Conway's game of life
	_transition_table[0][3] = 1;
	_transition_table[1][2] = 1;
	_transition_table[1][3] = 1;
};


void CellularAutomaton::_random_init_grid() {
	for (int y = 0; y < _height; y++) {
		for (int x = 0; x < _width; x++) {
			_grid[x][y] = _bdist(_rng);
		}
	}
}


const void CellularAutomaton::print_grid() {
	char printchars[2] = {' ', '0'};
	std::cout << std::endl;
	for (int y = 0; y < _height; y++) {
		for (int x = 0; x < _width; x++) {
			std::cout << printchars[_grid[x][y]];
		}
		std::cout << std::endl;
	}
}


void CellularAutomaton::step() {
	_count_live_neighbours();
	for (int y = 0; y < _height; y++) {
		for (int x = 0; x < _width; x++) {
			_grid[x][y] = _transition_table[_grid[x][y]][_num_neighbours_grid[x][y]];	// Apply rules for each cell
		}
	}
}


const void CellularAutomaton::_count_live_neighbours() {
	for (int y = 0; y < _height; y++) {
		for (int x = 0; x < _width; x++) {
			int neighbours[8][2] = {
				{(x - 1 + _width) % _width, (y - 1 + _height) % _height},
				{(x - 1 + _width) % _width, (y) % _height},
				{(x - 1 + _width) % _width, (y + 1) % _height},
				{(x) % _width, (y - 1 + _height) % _height},
				{(x) % _width, (y + 1) % _height},
				{(x + 1) % _width, (y - 1 + _height) % _height},
				{(x + 1) % _width, (y) % _height},
				{(x + 1) % _width, (y + 1) % _height},
			};
			_num_neighbours_grid[x][y] = 0;
			for (int i = 0; i < 8; i++) {
				_num_neighbours_grid[x][y] += _grid[neighbours[i][0]][neighbours[i][1]];
			}
		}
	}
}