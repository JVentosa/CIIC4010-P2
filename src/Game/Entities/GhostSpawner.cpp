#include "GhostSpawner.h"
#include "Ghost.h"

GhostSpawner::GhostSpawner(int x, int y, int width, int height,ofImage spriteSheet,int color) : Entity(x, y, width, height)
{
    switch(color)
    {
        case 1:
            sprite.load("images/Background.png");
            sprite.cropFrom(sprite, 455, 95,16, 16);
            break;
        case 2:
            sprite.load("images/Background.png");
            sprite.cropFrom(sprite, 455, 111,16, 16);
            break;
        case 3:
            sprite.load("images/Background.png");
            sprite.cropFrom(sprite, 455, 79,16, 16);
            break;
        case 4:
            sprite.load("images/Background.png");
            sprite.cropFrom(sprite, 455, 63,16, 16);
            break;
    }
};
