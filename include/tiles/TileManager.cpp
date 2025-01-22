#include "TileManager.h"
#include <algorithm>  // For std::remove_if
#include <iostream>
#include <cassert> 
#include <Tile.hpp>
#include <vector> 

// allocate a 2d array of tiles
TileManager:TileManager() {
    allTiles = new Tile*[MAP_LEN];
    for (int r = 0; r < MAP_LEN; r++) {
        allTiles[r] = new Tile*[MAP_LEN];
        for (int c = 0; c < MAP_LEN; ++j) {
            allTiles[r][c] = new Tile();
        }
    }

}

// delete the allocated 2d array
TileManager::~TileManager() {
    //Free each sub-array
    for(int r = 0; r < MAP_LEN; r++) {
        delete[] allTiles[r];   
    }

    //Free the array of pointers
    delete[] allTiles;
}

void TileManager::addTile(Tile* tile) {
    allTiles.push_back(tile);
}
 
// Remove Tile item at location (r, c) [not implemented]
// requires that the tile exists
bool TileManager::removeTile(int r, int c) {

    assert(allTiles[r][c]); 
    //allTiles[r][c] = VOID TILE
}

Tile* TileManager::getTileByName(const std::string& tileName) const {
    for (Tile* tile : allTiles) {
        if (tile->getName() == tileName) {
            return tile;
        }
    }
    return nullptr;         // Return nullptr if the tile is not found
}

Tile** TileManager::getAllTiles() const {
    return allTiles;
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
    bool use_reverse = true // Hard coded true for now

    std::vector<Tile*> connectedTiles; 

    if (use_reverse) {
        connectedTiles.push_back()


    }
}
