#include "Ghost.h"

Ghost::Ghost(int x, int y, int width, int height, ofImage spriteSheet): Entity(x, y, width, height){
    sprite.load("images/Background.png");
    sprite.cropFrom(sprite, 455, 95,16, 16);
    vector <ofImage> NotScaredVector;
    for(int i = 0; i < 7; i++)
    {
        sprite.load("images/Background.png");
        sprite.cropFrom(sprite, 455 + 14*i, 64,16, 16);
        NotScaredVector.push_back(sprite);
    }
    vector <ofImage> ScaredVector;
    for(int i = 0; i < 3; i++)
    {
        sprite.load("images/Background.png");
        sprite.cropFrom(sprite, 583 + 14*i, 95,16, 16);
        ScaredVector.push_back(sprite);
    }
    sprite.load("images/Background.png");
    sprite.cropFrom(sprite, 455, 95,16, 16);
    Scared = new Animation(1,ScaredVector);
    NotScared = new Animation(1,NotScaredVector);
}

void Ghost::render()
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