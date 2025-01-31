// HexGrid.cpp
#include "HexGrid.hpp"
#include <cmath>

HexGrid::HexGrid(int rows, int cols, float hexSize) : hexSize(hexSize) {
    generateGrid(rows, cols);
}

void HexGrid::generateGrid(int rows, int cols) {
    float width = hexSize * 2;
    float height = sqrt(3) * hexSize;
    
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            float x = col * width * 0.75f;
            float y = row * height + (col % 2) * (height / 2);
            hexagons.push_back({x, y});
        }
    }
}

void HexGrid::render(SDL_Renderer* renderer) {
    for (const auto& hex : hexagons) {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        for (int i = 0; i < 6; ++i) {
            float angle1 = M_PI / 3 * i;
            float angle2 = M_PI / 3 * (i + 1);
            int x1 = static_cast<int>(hex.x + hexSize * cos(angle1));
            int y1 = static_cast<int>(hex.y + hexSize * sin(angle1));
            int x2 = static_cast<int>(hex.x + hexSize * cos(angle2));
            int y2 = static_cast<int>(hex.y + hexSize * sin(angle2));
            SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
        }
    }
}
