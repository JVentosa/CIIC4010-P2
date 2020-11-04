#pragma once
#include "EntityManager.h"
#include "Entity.h"
#include "Ghost.h"


class GhostSpawner : public Ghost
{  
    public:
    Animation *Scared;
    Animation *NotScared;
    void render();
    GhostSpawner(int, int, int , int,ofImage,int, EntityManager*);
};
