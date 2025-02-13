#include <SDL2/SDL.h>
#include <vector>
#include <cmath>
#include "../tiles/TileManager.hpp"

struct Coords {
    int x;
    int y;
};

class HexGrid {
public:
    HexGrid(TileManager* tm);
    void render(SDL_Renderer* renderer);
    void drawHexagon(SDL_Renderer* renderer, float x, float y, const Color color);
    void setColor(SDL_Renderer* renderer, const Color color);
private:

    /* Helper functions to calculate hexagon */
    float getHeight(float cRadius);
    float getApothem(float cRadius);
    bool isEven(int x);

    /* Variables to help organize the grid */
    float cRadius;
    Coords startingCoords; 

    /* Actual Tile Data */
    TileManager* tileManager;
    
};