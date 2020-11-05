#pragma once
#include "Entity.h"
#include "Animation.h"
#include "EntityManager.h"
#include "Block.h"


enum GFace{
    UPGhost,
    DOWNGhost,
    LEFTGhost,
    RIGHTGhost
};

class Ghost: public Entity{
    bool Mortal = false;
    Animation *Scared;
<<<<<<< HEAD
    Animation *NotScaredUP;
    Animation *NotScaredDown;
    Animation *NotScaredLeft;
    Animation *NotScaredRight;
    bool canghostmove;
    GFace faze = UPGhost;
    int speedghost = 2;
    EntityManager* em;
=======
    Animation *NotScared;
>>>>>>> Bugged-Ghost-Movement
    public:
    void tick();
    void render();
    void checkCollisions();
    Ghost(int, int, int, int, ofImage, EntityManager*);    
        
<<<<<<< HEAD
    bool getMortal(){return this->Mortal;}
    void setMortal(bool a)
    {
        if(!Mortal) Mortal = true;
        else Mortal = false;
    }
    void setfaze(GFace faze)
    {
        this->faze = faze;
    }  
=======
        bool getMortal(){return this->Mortal;}
        void setMortal(bool a)
        {
            if(!Mortal) Mortal = true;
            else Mortal = false;
        }

    private: 
    // Movement { }
    EntityManager* em;
    bool canghostmove;
    GFace gfacing = UPGhost;
    int speedghost = 2;


>>>>>>> Bugged-Ghost-Movement

};

