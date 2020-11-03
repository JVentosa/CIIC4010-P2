#pragma once
#include "Entity.h"
#include "Animation.h"

class Ghost: public Entity{
    bool Mortal = false;
    Animation *Scared;
    Animation *NotScared;
    public:
    void render();
        Ghost(int, int, int, int, ofImage);
        
        
        bool getMortal(){return this->Mortal;}
        void setMortal(bool a)
        {
            if(!Mortal) Mortal = true;
            else Mortal = false;
        }
};