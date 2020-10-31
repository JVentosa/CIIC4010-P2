#pragma once
#include "EntityManager.h"
#include "Entity.h"
#include "Ghost.h"


class GhostSpawner : public Ghost, public EntityManager
{
    public:
    EntityManager* entity;
    GhostSpawner(int, int, int , int,ofImage,int);
};
