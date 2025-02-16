// HexGrid.cpp
#include "HexGrid.hpp"
#include <cmath>
#include <vector>

#include <chrono>
#include <thread>

HexGrid::HexGrid(TileManager* tm) {
    cRadius = 50;
    startingCoords.x = 100;
    startingCoords.y = 100;

    tm->generateRandomGrid();
    tileManager = tm;
}   

/* Calculate the height of the entire hexagon (diameter from one side to another) */
float HexGrid::getHeight(float cRadius) {
    return getApothem(cRadius) * 2;
}

/* Distance between the radius and a vertex */
float HexGrid::getApothem(float cRadius) {
    return cRadius * cos(30);
}

/* Check if value is even */
bool HexGrid::isEven(int x) {
    return (x % 2 == 0);
}

void HexGrid::setColor(SDL_Renderer* renderer, const Color color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
}

// (Generated Code)
// Draw a single flat-topped hexagon centered at (x, y).
// For a flat-topped hexagon, we use angles of 0°, 60°, 120°, …, 300°.
void HexGrid::drawHexagon(SDL_Renderer* renderer, Coords tileCoords, const Color color) {
    const int NUM_POINTS = 6;
    SDL_Point points[NUM_POINTS + 1]; // +1 to close the polygon

    // For a flat-topped hexagon, the vertices are computed at:
    // angle = 0, 60, 120, 180, 240, and 300 degrees (converted to radians)
    for (int i = 0; i < NUM_POINTS; ++i) {
        float angle = M_PI / 3.0f * i; // M_PI/3 = 60° in radians
        points[i].x = static_cast<int>(tileCoords.x + cRadius * cos(angle));
        points[i].y = static_cast<int>(tileCoords.y + cRadius * sin(angle));
    }
    // Close the hexagon by repeating the first point.
    points[NUM_POINTS] = points[0];

    // Set the drawing color (e.g., white) and draw the hexagon outline.
    setColor(renderer, color);
    SDL_RenderDrawLines(renderer, points, NUM_POINTS + 1);
}

// Render a grid of flat-topped hexagons/
void HexGrid::render(SDL_Renderer* renderer) {

    // Clear all items that existed before 
    setColor(renderer, BLACK); // create black background
    SDL_RenderClear(renderer);

    const int cols = COLS; // number of columns in the grid
    const int rows = ROWS; // number of rows in the grid
    const float x_modifier = 1.75 * (cRadius / 100);
    const float y_modifier = 2 - (1 - cRadius / 100);
    float x_off = 1;

    for (int c = 0; c < cols; c++) {
        
        // base case modifier
        if (c > 0) {
            x_off = x_off + x_modifier;
        }
        
        // generate the up shifted column
        if (isEven(c)) { 
            for (int r = 0; r < rows; r++) {

                // Get Tile information
                Color tileColor = tileManager->getTile(r, c)->getColor();
                Coords tileCoords {
                    static_cast<int>(startingCoords.x * x_off), 
                     static_cast<int>(startingCoords.y + (r * cRadius * 2))
                };

                drawHexagon(renderer, tileCoords, tileColor);
            }
        } else { // generate the down shifted column
            for (int r = 0; r < rows; r++) {

                // Get Tile information
                Color tileColor = tileManager->getTile(r, c)->getColor();

                Coords tileCoords {
                     static_cast<int>(startingCoords.x  * x_off), 
                     static_cast<int>((startingCoords.y * y_modifier) + (r * cRadius * 2))
                };

                drawHexagon(renderer, tileCoords, tileColor);
            }
        }
        
    }

    // display updated changes
    SDL_RenderPresent(renderer);
}

/* Function not in usage */
void HexGrid::updateDisplayedTileColor(SDL_Renderer* renderer, Tile* tile) {
    drawHexagon(renderer, tile->getCoords(), tile->getColor());
}

void HexGrid::rippleEffect(SDL_Renderer* renderer, Tile* tile) {
    tile->setColor(RED);
    render(renderer);
    

    /* BUGGED FUNCTION: SEGFAULT. */
    std::vector<Tile*> connectedTiles = tileManager->getConnectedTiles(tile); 

    // std::this_thread::sleep_for(std::chrono::nanoseconds(10));

    // for (auto &tile : connectedTiles) {

    //     if (tile) { 
    //         rippleEffect(renderer, tile);
    //     }
        
    // }

    // std::this_thread::sleep_for(std::chrono::nanoseconds(10));


}