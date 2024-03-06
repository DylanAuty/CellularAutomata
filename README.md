# CellularAutomaton
A simulator for simple 2D cellular automata, like Conway's Game of Life, written in C++.

Rules are expressed as a state transition table: in each state, what is the mapping from number of neighbours to next state?
The simulation is printed to the terminal, step by step.

Below is the simulator running Conway's Game of Life:

<img src="demo.gif" alt="Gif of the simulator running Conway's Game of Life.">


## Compilation and Running
To compile, `cd` to the directory containing this readme and run the following:
```bash
mkdir build && cd build
cmake .. && make
```

This emits an executable at `build/cellularAutomata`. This instantiates the simulation and then prints each step to the terminal, one by one.
