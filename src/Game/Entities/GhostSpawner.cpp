#include "GhostSpawner.h"

GhostSpawner::GhostSpawner(int x, int y, int width, int height,ofImage spriteSheet,int color) : Ghost(x, y, width, height,spriteSheet)
{
    vector <ofImage> NotScaredVector;
    vector <ofImage> ScaredVector;
    switch(color)
    {
        case 1:
            if(getMortal() == false)
            {
                sprite.load("images/Background.png");
                for(int i = 0; i < 7; i++)
                {
                    sprite.load("images/Background.png");
                    sprite.cropFrom(sprite, 455 + 14*i, 95,16, 16);
                    NotScaredVector.push_back(sprite);
                }   
                break;
                }
            else 
            {
                for(int i = 0; i < 3; i++)
                {
                    sprite.load("images/Background.png");
                    sprite.cropFrom(sprite, 583 + 14*i, 95,16, 16);
                    ScaredVector.push_back(sprite);
                }
                break;
            }
        case 2:
            if(getMortal() == false)
            {
                sprite.load("images/Background.png");
                for(int i = 0; i < 7; i++)
                {
                    sprite.load("images/Background.png");
                    sprite.cropFrom(sprite, 455 + 14*i, 111,16, 16);
                    NotScaredVector.push_back(sprite);
                }  
                break;
            }
            else
            {
                for(int i = 0; i < 3; i++)
                {
                    sprite.load("images/Background.png");
                    sprite.cropFrom(sprite, 583 + 14*i, 95,16, 16);
                    ScaredVector.push_back(sprite);
                }
                break;
            }
        case 3:
            if(getMortal() == false)
            {
                sprite.load("images/Background.png");
                for(int i = 0; i < 7; i++)
                {
                    sprite.load("images/Background.png");
                    sprite.cropFrom(sprite, 455 + 14*i, 79,16, 16);
                    NotScaredVector.push_back(sprite);
                }  
                break;
            }
            else
            {
                for(int i = 0; i < 3; i++)
                {
                    sprite.load("images/Background.png");
                    sprite.cropFrom(sprite, 583 + 14*i, 95,16, 16);
                    ScaredVector.push_back(sprite);
                }
                break;
            }
        case 4:
            if(getMortal() == false){
                sprite.load("images/Background.png");
                for(int i = 0; i < 7; i++)
                {
                    sprite.load("images/Background.png");
                    sprite.cropFrom(sprite, 455 + 14*i, 64,16, 16);
                    NotScaredVector.push_back(sprite);
                }  
                break;
            }
            else
            {
                for(int i = 0; i < 3; i++)
                {
                    sprite.load("images/Background.png");
                    sprite.cropFrom(sprite, 583 + 14*i, 95,16, 16);
                    ScaredVector.push_back(sprite);
                }
                break;
            }
    }
    Scared = new Animation(1,ScaredVector);
    NotScared = new Animation(1,NotScaredVector);
}
void GhostSpawner::render()
{
    if(getMortal() == false)
    {
        NotScared->getCurrentFrame().draw(x, y, width, height);
    }
    else 
    {
        Scared->getCurrentFrame().draw(x, y, width, height);
    }
}