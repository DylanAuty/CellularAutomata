#ifndef CELLULARAUTOMATON_HPP
#define CELLULARAUTOMATON_HPP

#include <vector>
#include <map>
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
		const void print_grid();

		/** Steps the simulation once. */
		void step();

	private:
		int _width;		// Stores grid width
		int _height;	// Stores grid height
		int _seed;		// Stores random seed used by RNG

		/** Transition table map for each cell: current_state -> (num_neighbours -> next_state) */
		std::map<int, std::map<int, int>> _transition_table;

		std::vector<std::vector<int>> _grid;				// Stores grid of cell states
		std::vector<std::vector<int>> _num_neighbours_grid;	// Stores number of neighbours each cell has.
		std::mt19937 _rng;	// RNG
		std::bernoulli_distribution _bdist;			// Bernoulli distribution to sample from
		std::uniform_int_distribution<int> _udist;	// Uniform distribution to sample from, for state init.

		/** Randomly initialise cell states in the grid. */
		void _random_init_grid();

		/** Initialise the state transition table. Hardcoded game of life at present. */
		void _init_transition_table();

		/** Computes number of neighbours each cell currently has.*/
		const void _count_live_neighbours();
};

#endif