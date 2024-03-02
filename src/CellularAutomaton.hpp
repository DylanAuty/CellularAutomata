#ifndef CELLULARAUTOMATON_HPP
#define CELLULARAUTOMATON_HPP

#include <vector>
#include <random>


/** 
 * Class to represent and simulate a cellular automaton with a given rule.
 * Grid is assumed to exist on a torus.
 */
class CellularAutomaton {
	public:
		/**
		 * Constructor with user-specified seed.
		 * 
		 * @param height height of grid to generate.
		 * @param width width of grid to generate
		 * @param seed random seed to use.
		 */
		CellularAutomaton(int height, int width, int seed);
		/**
		 * Constructor with random seed.
		 * 
		 * @param height height of grid to generate.
		 * @param width width of grid to generate
		 */
		CellularAutomaton(int height, int width);

		/** Prints grid to stdout. Assumes 2 states only. */
		void print_grid();

		/** Steps the simulation once. */
		void step();

	private:
		int _width;		// Stores grid width
		int _height;	// Stores grid height
		int _seed;		// Stores random seed used by RNG
		const int _rule_born[1] = {3};			// How many neighbours are needed to have a cell turn on
		const int _rule_survive[2] = {2, 3};	// How many neighbours are needed for a cell to survive
		std::vector<std::vector<bool>> _grid;				// Stores grid of cell states
		std::vector<std::vector<int>> _num_neighbours_grid;	// Stores number of neighbours each cell has.
		std::mt19937 _rng;	// RNG
		std::bernoulli_distribution _bdist;		// Bernoulli distribution to sample from
		
		/** Randomly initialise cell states in the grid. */
		void _random_init_grid();

		/** Computes number of neighbours each cell currently has.*/
		void _count_live_neighbours();
};

#endif