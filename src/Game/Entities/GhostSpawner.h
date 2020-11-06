#pragma once
#include "EntityManager.h"
#include "Entity.h"
#include "Ghost.h"

enum GFace1{
    UPGhost1,
    DOWNGhost1,
    LEFTGhost1,
    RIGHTGhost1
};



class GhostSpawner : public Ghost
{  
    int count1 = 0;
    int speedghost1 = 2;
    bool canghostmove1 = true;
    EntityManager* em;
    GFace1 faze1 = UPGhost1;
    public:
    Animation *NotScaredUP1;
    Animation *NotScaredDown1;
    Animation *NotScaredLeft1;
    Animation *NotScaredRight1;
    Animation *Scared;
    Animation *NotScared;
    void render();
    void checkCollisions1();
    void tick();
    GhostSpawner(int, int, int , int,ofImage,int, EntityManager*);
    void setfaze1(GFace1 faze1)
    {
        this->faze1 = faze1;
    }  
};
