#pragma once
#include "Animation.h"

#include "EntityManager.h"

enum FACING {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Player: public Entity{

    private:
        int color = 1;
        int health = 500;
        int score = 0;
        bool canMove;
        int speed = 2;
        bool walking = false;
        FACING facing = DOWN;
        ofImage up, down, left, right;
        Animation *walkUp;
        Animation *walkDown;
        Animation *walkLeft;
        Animation *walkRight;
        EntityManager* em;

    public:
        Player(int, int, int , int, EntityManager*);
        int getHealth(){return health;}
        int getScore(){return score;}
       
    
        void tick();
        void render();
        void keyPressed(int);
        void keyReleased(int);
        void damage(Entity* damageSource);
        void mousePressed(int, int, int);
        void reset();
        void setFacing(FACING facing);
        void checkCollisions();
        void die();
        ofSoundPlayer   mySound;
        ofSoundPlayer   mySound2;
        ofSoundPlayer dead;
        ofSoundPlayer ghost;
        ofSoundPlayer life;
        ofSoundPlayer low;

        void setScore(int n){this->score = n;}
        void setHealth(int n){this->health = n;}
};