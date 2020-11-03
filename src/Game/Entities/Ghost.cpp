#include "Ghost.h"

Ghost::Ghost(int x, int y, int width, int height, ofImage spriteSheet, EntityManager* em): Entity(x, y, width, height){
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

void Ghost::tick(){
    canghostmove = true;
    checkCollisions();
    if(canghostmove){
        if(gfacing == DOWNGhost){
            y += speed;
        }
        else if(gfacing == UPGhost){
            y -= speed;
        }
        else if(gfacing == LEFTGhost){
            x -= speed;
        }
        else if(gfacing == RIGHTGhost){
            x += speed;
        }
    }
}

void Ghost::setGfacing(GFace gfacing){
    this->gfacing = gfacing;
}

void Ghost::checkCollisions(){
    for(Block* block: em->blocks){
        switch(gfacing){
            case UPGhost:
                if(this->getBounds(x, y-speed).intersects(block->getBounds())){
                    canghostmove = false;
            if(facing != 0){
                switch(facing){
                    case 0:
                        setGfacing(UPGhost);
                        canghostmove = false;
                        break;
                    case 1:
                        setGfacing(DOWNGhost);
                        canghostmove = false;
                        break;
                    case 2:
                        setGfacing(LEFTGhost);
                        canghostmove = false;
                        break;
                    case 3:
                        setGfacing(RIGHTGhost);
                        canghostmove = false;
                        break;
                    default:
                        break;
                    }
                }
            }
            case DOWNGhost:
                if(this->getBounds(x, y-speed).intersects(block->getBounds())){
                    canghostmove = false;
            if(facing != 1){
                switch(facing){
                    case 0:
                        setGfacing(UPGhost);
                        canghostmove = false;
                        break;
                    case 1:
                        setGfacing(DOWNGhost);
                        canghostmove = false;
                        break;
                    case 2:
                        setGfacing(LEFTGhost);
                        canghostmove = false;
                        break;
                    case 3:
                        setGfacing(RIGHTGhost);
                        canghostmove = false;
                        break;

                    default:
                        break;
                }
            }
        }
            case LEFTGhost:
                if(this->getBounds(x, y-speed).intersects(block->getBounds())){
                    canghostmove = false;
            if(facing != 2){
                switch(facing){
                    case 0:
                        setGfacing(UPGhost);
                        canghostmove = false;
                        break;
                    case 1:
                        setGfacing(DOWNGhost);
                        canghostmove = false;
                        break;
                    case 2:
                        setGfacing(LEFTGhost);
                        canghostmove = false;
                        break;
                    case 3:
                        setGfacing(RIGHTGhost);
                        canghostmove = false;
                        break;
                    default:
                        break;
                    }
                }
            }
            case RIGHTGhost:
                if(this->getBounds(x, y-speed).intersects(block->getBounds())){
                    canghostmove = false;
            if(facing != 3){
                switch(facing){
                    case 0:
                        setGfacing(UPGhost);
                        canghostmove = false;
                        break;
                    case 1:
                        setGfacing(DOWNGhost);
                        canghostmove = false;
                        break;
                    case 2:
                        setGfacing(LEFTGhost);
                        canghostmove = false;
                        break;
                    case 3:
                        setGfacing(RIGHTGhost);
                        canghostmove = false;
                        break;
                    default:
                        break;
                    }
                }
            }
            break;
        }
    }
}