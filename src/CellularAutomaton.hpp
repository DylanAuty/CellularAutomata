#ifndef CELLULARAUTOMATON_HPP
#define CELLULARAUTOMATON_HPP

#include <vector>
#include <random>

class CellularAutomaton {
	public:
		CellularAutomaton(int height, int width, int seed);
		CellularAutomaton(int height, int width);

		void print_grid();

	private:
		int _width;
		int _height;
		int _seed;
		std::vector<std::vector<bool>> _grid;
		std::mt19937 _rng;
		std::uniform_int_distribution<std::mt19937::result_type> _udist;	// Using uniform instead of Bernoulli to allow multiple states
		
		void _random_init_grid();
};

#endif