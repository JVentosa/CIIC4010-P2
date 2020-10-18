#include "EntityManager.h"
#include "Entity.h"


class GhostSpawner : public Entity, public EntityManager
{
    public:
    EntityManager* entity;
    GhostSpawner(int, int, int , int, EntityManager*,ofImage,int);
};
