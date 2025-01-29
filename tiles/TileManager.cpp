#include "TileManager.hpp"
#include <algorithm>  // For std::remove_if
#include <iostream>
#include <cassert> 
#include "Tile.hpp"
#include <vector> 
#include <functional>


// allocate a 2d array of tiles
TileManager::TileManager() {

}

// delete the allocated 2d array
TileManager::~TileManager() {
    //Free each sub-array
    for(int r = 0; r < MAP_LEN; r++) {
        for (int c = 0; c < MAP_LEN; c++) {
            delete allTiles[r][c];
        }
    }

    //Free the array of pointers
    delete[] allTiles;
}
 
// Remove Tile item at location (r, c) [not implemented]
// requires that the tile exists
bool TileManager::removeTile(int r, int c) {

    assert(allTiles[r][c]); 
    //allTiles[r][c] = VOID TILE
}

Tile* TileManager::getTileByName(const std::string& tileName) const {\

    for(int r = 0; r < MAP_LEN; r++) {
        for (int c = 0; c < MAP_LEN; c++) {
            if (allTiles[r][c]->getName() == tileName) {
                return allTiles[r][c];
            }
        }
    }

    return nullptr;         // Return nullptr if the tile is not found
}

// Tile*** TileManager::getAllTiles() {
//     return allTiles;
// }

bool is_in_range(int x) {
    if ((x > 0) || (x < MAP_LEN)) {
        return true;
    }

    return false;
}

/* Helper functions to simplify */
Tile* TileManager::getTopItem(int r, int c) {

    int newRow = r - 1;

    // error checking if we're out of bounds
    if (!is_in_range(newRow)) {
        return nullptr;
    }

    return allTiles[newRow][c];
}

Tile* TileManager::getBottomItem(int r, int c) {

    int newRow = r + 1;

    // error checking if we're out of bounds
    if (!is_in_range(newRow)) {
        return nullptr;
    }
    
    return allTiles[newRow][c];

}

Tile* TileManager::getRightItem(int r, int c) {
    int newCol = c + 1;

    // error checking if we're out of bounds
    if (!is_in_range(newCol)) {
        return nullptr;
    }

    return allTiles[r][newCol];
}

Tile* TileManager::getLeftItem(int r, int c) {
    int newCol = c - 1;

    // error checking if we're out of bounds
    if (!is_in_range(newCol)) {
        return nullptr;
    }

    return allTiles[r][newCol];

}

Tile* TileManager::getTopRightItem(int r, int c) {

    int newRow = r - 1;
    int newCol = c + 1;

    if (is_in_range(newCol) && is_in_range(newRow)) {
        return allTiles[newRow][newCol];
    }

    return nullptr;
}

Tile* TileManager::getTopLeftItem(int r, int c) {
    int newRow = r - 1;
    int newCol = c - 1;

    if (is_in_range(newCol) && is_in_range(newRow)) {
        return allTiles[newRow][newCol];
    }

    return nullptr;
}

Tile* TileManager::getBottomLeftItem(int r, int c) {
    int newRow = r + 1;
    int newCol = c - 1;

    if (is_in_range(newCol) && is_in_range(newRow)) {
        return allTiles[newRow][newCol];
    }

    return nullptr;
}

Tile* TileManager::getBottomRightItem(int r, int c) {
    int newRow = r + 1;
    int newCol = c + 1;

    if (is_in_range(newCol) && is_in_range(newRow)) {
        return allTiles[newRow][newCol];
    }

    return nullptr;
}

// helper function to push back
void push_back_non_null(Tile* foundTile, std::vector<Tile*> tiles) {
    if (foundTile) {
        tiles.push_back(foundTile);
    }
}

/*  Purpose: Return all the tiles connected to the given tile
    use 'gold general' pattern to determine which tiles are closest

                x * x               * * *
    NORMAL:     * o *    REVERSE:   * o *
                * * *               x * x
    
    where * refers to a tile that is in usage
*/
std::vector<Tile*> TileManager::getConnectedTiles(Tile* tile) {

    // do some algorithm to determine using reverse or normal
    bool use_reverse = true; // Hard coded true for now

    std::vector<Tile*> connectedTiles;
    int tileRow = 0;
    int tileCol = 0; 

    // use the reverse pattern
    if (use_reverse) {
        push_back_non_null(getTopItem(tileRow, tileCol), connectedTiles);
        push_back_non_null(getBottomItem(tileRow, tileCol), connectedTiles);
        push_back_non_null(getTopRightItem(tileRow, tileCol), connectedTiles);
        push_back_non_null(getTopLeftItem(tileRow, tileCol), connectedTiles);
        push_back_non_null(getLeftItem(tileRow, tileCol), connectedTiles);
        push_back_non_null(getRightItem(tileRow, tileCol), connectedTiles);
    } else {    // use the standard pattern
        push_back_non_null(getTopItem(tileRow, tileCol), connectedTiles);
        push_back_non_null(getBottomItem(tileRow, tileCol), connectedTiles);
        push_back_non_null(getBottomRightItem(tileRow, tileCol), connectedTiles);
        push_back_non_null(getBottomLeftItem(tileRow, tileCol), connectedTiles);
        push_back_non_null(getLeftItem(tileRow, tileCol), connectedTiles);
        push_back_non_null(getRightItem(tileRow, tileCol), connectedTiles);
    }

    return connectedTiles;
}
