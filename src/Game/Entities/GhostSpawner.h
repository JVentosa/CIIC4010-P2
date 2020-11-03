#pragma once
#include "EntityManager.h"
#include "Entity.h"
#include "Ghost.h"


class GhostSpawner : public Ghost, public EntityManager
{
    Animation *Scared;
    Animation *NotScared;
    public:
    EntityManager* entity;
    void render();
    GhostSpawner(int, int, int , int,ofImage,int);
};
