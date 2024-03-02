#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include "CellularAutomaton.hpp"

CellularAutomaton::CellularAutomaton(int height, int width, int seed)
: _width(width), _height(height), _seed(seed), _udist(0, 1) {
	std::cout << "Cellular Automaton with width " << width << " and height " << height << std::endl;
	_rng.seed(_seed);

	_grid = std::vector<std::vector<bool>>(width, std::vector<bool>(height, false));
	_num_neighbours_grid = std::vector<std::vector<int>>(width, std::vector<int>(height, 0));
	_random_init_grid();
};


CellularAutomaton::CellularAutomaton(int height, int width)
: _width(width), _height(height), _udist(0, 1) {
	std::cout << "Cellular Automaton with width " << width << " and height " << height << std::endl;
	_seed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	_rng.seed(_seed);
	_grid = std::vector<std::vector<bool>>(width, std::vector<bool>(height, false));
	_num_neighbours_grid = std::vector<std::vector<int>>(width, std::vector<int>(height, 0));
	_random_init_grid();
};

void CellularAutomaton::_random_init_grid() {
	for (int y = 0; y < _height; y++) {
		for (int x = 0; x < _width; x++) {
			_grid[x][y] = _udist(_rng);
		}
	}
}

void CellularAutomaton::print_grid() {
	char printchars[2] = {' ', '#'};
	for (int y = 0; y < _height; y++) {
		for (int x = 0; x < _width; x++) {
			std::cout << printchars[_grid[x][y]];
		}
		std::cout << std::endl;
	}
}

void CellularAutomaton::step() {
	_count_live_neighbours();
}

void CellularAutomaton::_count_live_neighbours() {
	for (int y = 0; y < _height; y++) {
		for (int x = 0; x < _height; x++) {
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