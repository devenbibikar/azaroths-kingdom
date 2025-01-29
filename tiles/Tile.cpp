#include <algorithm>
#include <complex>
#include <iostream>
#include <iterator>
#include <vector>

#define NUM_CONNECT

class Tile {

    public:     
        ~Tile();
        Tile(std::string name) {
            std::fill_n(connectedTiles, NUM_CONNECTED, nullptr);
            this->name = name;
        };

        const static int NUM_CONNECTED = 5;
        Tile* connectedTiles[NUM_CONNECTED];
        std::string name;

        // return string name of object
        const std::string& Tile::getName();
};


const std::string& Tile::getName() {
    return name;
}