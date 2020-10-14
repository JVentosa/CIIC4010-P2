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
        bool playingSound = false;
        int health = 300;
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
        int getHealth(){return this->health;}
        int getScore(){return this->score;}
        bool getSound(){return this->playingSound;}
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

        void setScore(int n){this->score = n;}
        void setHealth(int n){this->health = n;}
        void setSound()
        {
            if(this->playingSound == true)
            {
                this->playingSound = false;
            }
            else this->playingSound = true;
        }
};