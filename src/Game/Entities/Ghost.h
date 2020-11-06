#pragma once
#include "Entity.h"
#include "Animation.h"
#include "EntityManager.h"
#include "Block.h"
#include "Player.h"


enum GFace{
    UPGhost,
    DOWNGhost,
    LEFTGhost,
    RIGHTGhost
};

class Ghost: public Entity{
    bool Mortal = false;
    Animation *Scared;
    int count = 0;
    Animation *NotScaredUP;
    Animation *NotScaredDown;
    Animation *NotScaredLeft;
    Animation *NotScaredRight;
    bool canghostmove;
    GFace faze = UPGhost;
    int speedghost = 2;
    EntityManager* em;

    Animation *NotScared;

    public:
    void tick();
    void render();
    void checkCollisions();
    Ghost(int, int, int, int, ofImage, EntityManager*);    
        

    bool getMortal(){return this->Mortal;}
    void setMortal()
    {
        if(!Mortal) Mortal = true;
        else Mortal = false;
    }
    void setfaze(GFace faze)
    {
        this->faze = faze;
    }  


};

