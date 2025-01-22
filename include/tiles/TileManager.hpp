#ifndef TILEMANAGER_H
#define TILEMANAGER_H

#define MAP_LEN 5

#include <vector>
#include <string>
#include "tiles/Tile.hpp"

class TileManager {
private:
    Tile* allTiles[MAP_LEN][MAP_LEN];

public:
    // Destructor to clean up dynamically allocated tiles
    ~TileManager();
    TileManager();

    // Method to remove a tile from the manager
    bool removeTile(const std::string& tileName);

    // Getters
    Tile* getTileByName(const std::string& tileName) const;
    Tile** getAllTiles();

    // Utility methods
    std::vector<Tile*> getConnectedTiles(Tile* tile) const;
};

#endif // TILEMANAGER_H
