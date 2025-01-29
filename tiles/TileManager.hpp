#define TILEMANAGER_H

#define MAP_LEN 5

#include <vector>
#include <string>
#include "Tile.hpp"
#include <array>

class TileManager {
private:
    Tile* allTiles[MAP_LEN][MAP_LEN];

public:
    // Destructor to clean up dynamically allocated tiles
    ~TileManager();
    TileManager();

    // Method to remove a tile from the manager
    bool removeTile(int r, int c);

    // Getters
    Tile* getTileByName(const std::string& tileName) const;
    Tile *getTopItem(int r, int c);
    Tile *getBottomItem(int r, int c);
    Tile *getRightItem(int r, int c);
    Tile *getLeftItem(int r, int c);
    Tile *getTopRightItem(int r, int c);
    Tile *getTopLeftItem(int r, int c);
    Tile *getBottomLeftItem(int r, int c);
    Tile *getBottomRightItem(int r, int c);
    std::vector<Tile *> TileManager::getConnectedTiles(Tile *tile);
};
