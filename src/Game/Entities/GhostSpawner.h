#include "EntityManager.h"
#include "Entity.h"


class GhostSpawner : public Entity, public EntityManager
{
    bool NewGhost = false;
    public:
    EntityManager* entity;
    GhostSpawner(int, int, int , int, EntityManager*,ofImage);
    void Spawner();
    bool getNewGhost(){return this->NewGhost;}
    void setNewGhost()
    {
        if(NewGhost) NewGhost = false;
        else NewGhost = true;
    }
};
