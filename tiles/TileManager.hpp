#define ROWS 10
#define COLS 20

#include <vector>
#include <string>
#include "Tile.hpp"
#include <vector>

class TileManager {
    private:
        std::vector<std::vector<Tile*>> allTiles;

    public:
        // Destructor to clean up dynamically allocated tiles
        ~TileManager();
        TileManager();

        // Method to remove a tile from the manager
        bool removeTile(int r, int c);

        // Getters
        Tile *getTileByName(const std::string& tileName) const;
        Tile *getTopItem(int r, int c);
        Tile *getBottomItem(int r, int c);
        Tile *getRightItem(int r, int c);
        Tile *getLeftItem(int r, int c);
        Tile *getTopRightItem(int r, int c);
        Tile *getTopLeftItem(int r, int c);
        Tile *getBottomLeftItem(int r, int c);
        Tile *getBottomRightItem(int r, int c);
        std::vector<Tile *> getConnectedTiles(Tile *tile);
        void generateRandomGrid();
};
