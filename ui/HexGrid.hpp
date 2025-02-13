// HexGrid.hpp
#ifndef HEXGRID_HPP
#define HEXGRID_HPP

#include <SDL2/SDL.h>
#include <vector>
#include <cmath>

// Defined Colors 
const int WHITE[3] = {255, 255, 255};
const int BLACK[3] = {0, 0, 0};

struct Coords {
    int x;
    int y;
};

class HexGrid {
public:
    HexGrid();
    void render(SDL_Renderer* renderer);
    void drawHexagon(SDL_Renderer* renderer, float x, float y, const int color[3]);
private:

    /* Helper functions to calculate hexagon */
    float getHeight(float cRadius);
    float getApothem(float cRadius);
    bool isEven(int x);


    float cRadius;
    Coords startingCoords; 
    
};

#endif // HEXGRID_HPP
