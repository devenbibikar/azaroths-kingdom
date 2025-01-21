#include "TileManager.h"
#include <algorithm>  // For std::remove_if
#include <iostream>
#include <cassert> 


TileManager::~TileManager() {
    // Clean up all dynamically allocated tiles
    for (Tile* tile : allTiles) {
        delete tile;
    }
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

// free a tile at a location
bool TileManager::freeTile(int r, int c) {
    assert(allTiles[r][c]);
    delete(allTiles[r][c]);
}

Tile* TileManager::getTileByName(const std::string& tileName) const {
    for (Tile* tile : allTiles) {
        if (tile->getName() == tileName) {
            return tile;
        }
    }
    return nullptr;         // Return nullptr if the tile is not found
}

const std::vector<Tile*>& TileManager::getAllTiles() const {
    return allTiles;
}
