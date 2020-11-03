#pragma once
#include "Entity.h"
#include "Animation.h"
#include "EntityManager.h"
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
    Animation *NotScared;
    public:
    EntityManager* em;
    void render();
        Ghost(int, int, int, int, ofImage, EntityManager*);
        
        
        bool getMortal(){return this->Mortal;}
        void setMortal(bool a)
        {
            if(!Mortal) Mortal = true;
            else Mortal = false;
        }

    private:
        // Movement { }
    bool canghostmove;
    GFace gfacing = UPGhost;
    int speed = 2;
    int facing = round(ofRandom(0,3));

    void tick();
    void setGfacing(GFace gfacing);
    void checkCollisions();

};

