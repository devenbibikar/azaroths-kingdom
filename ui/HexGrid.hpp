// HexGrid.hpp
#ifndef HEXGRID_HPP
#define HEXGRID_HPP

#include <SDL2/SDL.h>
#include <vector>
#include <cmath>

struct Coords {
    int x;
    int y;
};

class HexGrid {
public:
    HexGrid();
    void render(SDL_Renderer* renderer);
    void drawHexagon(SDL_Renderer* renderer, float x, float y);
private:

    /* Helper functions to calculate hexagon */
    float getHeight(float cRadius);
    float getApothem(float cRadius);
    bool isEven(int x);


    float cRadius;
    Coords startingCoords; 
    
};

#endif // HEXGRID_HPP
