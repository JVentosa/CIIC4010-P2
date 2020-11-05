#include "Ghost.h"
#include "EntityManager.h"
Ghost::Ghost(int x, int y, int width, int height, ofImage spriteSheet, EntityManager* em) : Entity(x, y, width, height)
{
    sprite.load("images/Background.png");
    sprite.cropFrom(sprite, 455, 95, 16, 16);
    vector<ofImage> NotScaredVector;
    for (int i = 0; i < 7; i++)
    {
        sprite.load("images/Background.png");
        sprite.cropFrom(sprite, 455 + 14 * i, 64, 16, 16);
        NotScaredVector.push_back(sprite);
    }
    vector<ofImage> ScaredVector;
    for (int i = 0; i < 3; i++)
    {
        sprite.load("images/Background.png");
        sprite.cropFrom(sprite, 583 + 14 * i, 95, 16, 16);
        ScaredVector.push_back(sprite);
    }
    sprite.load("images/Background.png");
    sprite.cropFrom(sprite, 455, 95, 16, 16);
    Scared = new Animation(1, ScaredVector);
    NotScared = new Animation(1, NotScaredVector);

    this->em=em;
}

void Ghost::render()
{
    if (getMortal() == false)
    {
        NotScared->getCurrentFrame().draw(x, y, width, height);
    }
    else
    {
        Scared->getCurrentFrame().draw(x, y, width, height);
    }
}

void Ghost::setGfacing(GFace gfacing)
{
    this->gfacing = gfacing;
}

void Ghost::tick()
{
    canghostmove = true;
    checkCollisionsGhost();
    if (canghostmove)
    {
        if (gfacing == DOWNGhost)
        {
            y += speedghost;
        }
        else if (gfacing == UPGhost)
        {
            y -= speedghost;
        }
        else if (gfacing == LEFTGhost)
        {
            x -= speedghost;
        }
        else if (gfacing == RIGHTGhost)
        {
            x += speedghost;
        }
    }
}

void Ghost::checkCollisionsGhost()
{
    for (Block* block: em->blocks)
    {
        switch (gfacing)
        {
        case UPGhost:
            if (this->getBounds(x, y - speedghost).intersects(block->getBounds()))
            {
                int facing = round(ofRandom(0,3));
                canghostmove = false;
                if (facing != 0)
                {
                    switch (facing)
                    {
                    case 0:
                        setGfacing(UPGhost);
                        break;
                    case 1:
                        setGfacing(DOWNGhost);
                        canghostmove = false;
                        break;
                    case 2:
                        setGfacing(LEFTGhost);
                        break;
                    case 3:
                        setGfacing(RIGHTGhost);
                        break;
                    default:
                        break;
                    }
                }
            }
            break;
        case DOWNGhost:
            if (this->getBounds(x, y+speedghost).intersects(block->getBounds()))
            {
                int facing = round(ofRandom(0,3));
                canghostmove = false;
                if (facing != 1)
                {
                    switch (facing)
                    {
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
                        break;
                    case 3:
                        setGfacing(RIGHTGhost);
                        break;

                    default:
                        break;
                    }
                }
            }
            break;
        case LEFTGhost:
            if (this->getBounds(x-speedghost, y).intersects(block->getBounds()))
            {
                int facing = round(ofRandom(0,3));
                canghostmove = false;
                if (facing != 2)
                {
                    switch (facing)
                    {
                    case 0:
                        setGfacing(UPGhost);
                        break;
                    case 1:
                        setGfacing(DOWNGhost);
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
        case RIGHTGhost:
            if (this->getBounds(x + speedghost, y).intersects(block->getBounds()))
            {
                int facing = round(ofRandom(0,3));
                canghostmove = false;
                if (facing != 3)
                {
                    switch (facing)
                    {
                    case 0:
                        setGfacing(UPGhost);
                        break;
                    case 1:
                        setGfacing(DOWNGhost);
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