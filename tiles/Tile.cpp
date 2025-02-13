#include <algorithm>
#include <complex>
#include <iostream>
#include <iterator>
#include <vector>
#include "Tile.hpp"

Tile::~Tile() {
    // destroy something?
}

Tile::Tile(std::string name) {
    this->name = name;
};

const std::string& Tile::getName() {
    return name;
}


