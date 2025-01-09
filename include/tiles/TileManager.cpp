#include "TileManager.h"
#include <algorithm>  // For std::remove_if
#include <iostream>

TileManager::~TileManager() {
    // Clean up all dynamically allocated tiles
    for (Tile* tile : allTiles) {
        delete tile;
    }
}

void TileManager::addTile(Tile* tile) {
    allTiles.push_back(tile);
}

bool TileManager::removeTile(const std::string& tileName) {
    // Find the tile with the given name and remove it from the list
    auto it = std::remove_if(allTiles.begin(), allTiles.end(),
                             [&tileName](Tile* tile) { return tile->getName() == tileName; });

    if (it != allTiles.end()) {
        delete *it;          // Clean up the memory for the tile being removed
        allTiles.erase(it);  // Remove the tile from the list
        return true;
    }
    return false;            // Tile with the given name was not found
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
