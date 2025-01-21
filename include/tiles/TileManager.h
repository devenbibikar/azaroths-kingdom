#ifndef TILEMANAGER_H
#define TILEMANAGER_H

#define MAP_LEN 5

#include <vector>
#include <string>
#include "tiles/Tile.h"

class TileManager {
private:
    Tile** matrix = new Tile*[MAP_LEN];

public:
    // Destructor to clean up dynamically allocated tiles
    ~TileManager();

    // Method to add a new tile to the manager
    void addTile(Tile* tile);

    // Method to remove a tile from the manager
    bool removeTile(const std::string& tileName);

    // Getters
    Tile* getTileByName(const std::string& tileName) const;
    const std::vector<Tile*>& getAllTiles() const;

    // Utility methods
    std::vector<Tile*> getConnectedTiles(Tile* tile) const;
};

#endif // TILEMANAGER_H
