// HexGrid.hpp
#ifndef HEXGRID_HPP
#define HEXGRID_HPP

#include <SDL2/SDL.h>
#include <vector>
#include <cmath>

struct Hexagon {
    float x, y; // Center position
};

class HexGrid {
public:
    HexGrid(int rows, int cols, float hexSize);
    void render(SDL_Renderer* renderer);
private:
    std::vector<Hexagon> hexagons;
    float hexSize;
    void generateGrid(int rows, int cols);
};

#endif // HEXGRID_HPP
