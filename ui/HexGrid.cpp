// HexGrid.cpp
#include "HexGrid.hpp"
#include <cmath>
//#include "../tiles/TileManager.hpp"

HexGrid::HexGrid() {
    cRadius = 100;
    startingCoords.x = 100;
    startingCoords.y = 100;
}   

/* Calculate the height of the entire hexagon (diameter from one side to another) */
float HexGrid::getHeight(float cRadius) {
    return getApothem(cRadius) * 2;
}

float HexGrid::getApothem(float cRadius) {
    return cRadius * cos(30);
}

// Draw a single flat-topped hexagon centered at (x, y).
// For a flat-topped hexagon, we use angles of 0°, 60°, 120°, …, 300°.
void HexGrid::drawHexagon(SDL_Renderer* renderer, float x, float y) {
    const int NUM_POINTS = 6;
    SDL_Point points[NUM_POINTS + 1]; // +1 to close the polygon

    // For a flat-topped hexagon, the vertices are computed at:
    // angle = 0, 60, 120, 180, 240, and 300 degrees (converted to radians)
    for (int i = 0; i < NUM_POINTS; ++i) {
        float angle = M_PI / 3.0f * i; // M_PI/3 = 60° in radians
        points[i].x = static_cast<int>(x + cRadius * cos(angle));
        points[i].y = static_cast<int>(y + cRadius * sin(angle));
    }
    // Close the hexagon by repeating the first point.
    points[NUM_POINTS] = points[0];

    // Set the drawing color (e.g., white) and draw the hexagon outline.
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawLines(renderer, points, NUM_POINTS + 1);
}

// Render a grid of flat-topped hexagons/
void HexGrid::render(SDL_Renderer* renderer) {
    const int cols = 5; // number of columns in the grid
    const int rows = 5; // number of rows in the grid

    int x;
    int y; 

    float x_off = 2.75;

    for (int c = 0; c < cols; c++) {
        // generate the up shifted column
        for (int r = 0; r < rows; r++) {
            y = startingCoords.y + (r * cRadius * 2);
            x = startingCoords.x;
            drawHexagon(renderer, x, y);
        }

        // generate the down shifted column
        for (int r = 0; r < rows; r++) {
            y = (startingCoords.y * 2) + (r * cRadius * 2);
            x = startingCoords.x  * x_off;
            drawHexagon(renderer, x, y);
        }
    }
    

    
}