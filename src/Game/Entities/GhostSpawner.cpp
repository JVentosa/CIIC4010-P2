#include "GhostSpawner.h"
#include "Ghost.h"

GhostSpawner::GhostSpawner(int x, int y, int width, int height, EntityManager* entity,ofImage spriteSheet) : Entity(x, y, width, height)
{
    this->entity = entity;
};
void GhostSpawner::Spawner()
{
    Ghost* ghost = new Ghost(x,y,width,height,sprite);
    entity->entities.push_back(ghost);
}