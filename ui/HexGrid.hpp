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

    float getHeight(float cRadius);
    float getApothem(float cRadius);


    float cRadius;
    Coords startingCoords; 
    
};

#endif // HEXGRID_HPP
