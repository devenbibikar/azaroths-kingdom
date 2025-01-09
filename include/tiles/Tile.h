#ifndef TILE_H
#define TILE_H

#include <algorithm>  // For std::fill_n
#include <complex>    // If needed, depending on your use case
#include <iostream>   // If needed for debugging or printing
#include <iterator>   // If needed, for iterators
#include <vector>     // If needed, for STL containers (e.g., std::vector)

class Tile {
public:
    // Destructor
    ~Tile();

    // Default Constructor: Initializes connectedTiles to nullptr
    Tile();

    // Static constant for the number of connected tiles
    const static int NUM_CONNECTED = 5;

    // Array to hold pointers to connected tiles
    Tile* connectedTiles[NUM_CONNECTED];
    
    const std::string& getName();

private:
    // You can add any private members or helper methods here
};

#endif
