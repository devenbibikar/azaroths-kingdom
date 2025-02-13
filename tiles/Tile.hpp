#ifndef TILE_H
#define TILE_H

#define NUM_CONNECTED 6

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
        Tile(std::string name);

        /* Tile Functions */
        const std::string& getName();

        /* UI Information */
        int color[3];
        float x;
        float y;

        /* Public Tile Information */
        

    private:
        // You can add any private members or helper methods here
        std::string name;
};

#endif
