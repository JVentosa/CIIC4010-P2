#include "GhostSpawner.h"
#include "Player.h"

GhostSpawner::GhostSpawner(int x, int y, int width, int height,ofImage spriteSheet,int color, EntityManager* em) : Entity(x, y, width, height)
{
    vector <ofImage> NotScaredVector;
    vector <ofImage> ScaredVector;
    vector<ofImage> NotScaredVectorLeft1;
    vector<ofImage> NotScaredVectorUp1;
    vector<ofImage> NotScaredVectorDown1;
    vector<ofImage> NotScaredVectorRight1;
    switch(color)
    {
        case 1:
    for (int i = 0; i < 2; i++)
    {
        sprite.load("images/Background.png");
        sprite.cropFrom(sprite, 457 + 16 * i, 95, 16, 16);
        NotScaredVectorRight1.push_back(sprite);
    }
        for (int i = 0; i < 2; i++)
    {
        sprite.load("images/Background.png");
        sprite.cropFrom(sprite, 489 + 16 * i, 95, 16, 16);
        NotScaredVectorLeft1.push_back(sprite);
    }    for (int i = 0; i < 2; i++)
    {
        sprite.load("images/Background.png");
        sprite.cropFrom(sprite, 521 + 16 * i, 95, 16, 16);
        NotScaredVectorUp1.push_back(sprite);
    }    for (int i = 0; i < 2; i++)
    {
        sprite.load("images/Background.png");
        sprite.cropFrom(sprite, 553 + 16 * i, 95, 16, 16);
        NotScaredVectorDown1.push_back(sprite);
    } 
        break;
        case 2:
    for (int i = 0; i < 2; i++)
    {
        sprite.load("images/Background.png");
        sprite.cropFrom(sprite, 457 + 16 * i, 111, 16, 16);
        NotScaredVectorRight1.push_back(sprite);
    }
        for (int i = 0; i < 2; i++)
    {
        sprite.load("images/Background.png");
        sprite.cropFrom(sprite, 489 + 16 * i, 111, 16, 16);
        NotScaredVectorLeft1.push_back(sprite);
    }    for (int i = 0; i < 2; i++)
    {
        sprite.load("images/Background.png");
        sprite.cropFrom(sprite, 521 + 16 * i, 111, 16, 16);
        NotScaredVectorUp1.push_back(sprite);
    }    for (int i = 0; i < 2; i++)
    {
        sprite.load("images/Background.png");
        sprite.cropFrom(sprite, 553 + 16 * i, 111, 16, 16);
        NotScaredVectorDown1.push_back(sprite);
    } 
        break;
        case 3:
    for (int i = 0; i < 2; i++)
    {
        sprite.load("images/Background.png");
        sprite.cropFrom(sprite, 457 + 16 * i, 79, 16, 16);
        NotScaredVectorRight1.push_back(sprite);
    }
        for (int i = 0; i < 2; i++)
    {
        sprite.load("images/Background.png");
        sprite.cropFrom(sprite, 489 + 16 * i, 79, 16, 16);
        NotScaredVectorLeft1.push_back(sprite);
    }    for (int i = 0; i < 2; i++)
    {
        sprite.load("images/Background.png");
        sprite.cropFrom(sprite, 521 + 16 * i, 79, 16, 16);
        NotScaredVectorUp1.push_back(sprite);
    }    for (int i = 0; i < 2; i++)
    {
        sprite.load("images/Background.png");
        sprite.cropFrom(sprite, 553 + 16 * i, 79, 16, 16);
        NotScaredVectorDown1.push_back(sprite);
    } 
        break;
                break;
        case 4:
    for (int i = 0; i < 2; i++)
    {
        sprite.load("images/Background.png");
        sprite.cropFrom(sprite, 457 + 16 * i, 64, 16, 16);
        NotScaredVectorRight1.push_back(sprite);
    }
        for (int i = 0; i < 2; i++)
    {
        sprite.load("images/Background.png");
        sprite.cropFrom(sprite, 489 + 16 * i, 64, 16, 16);
        NotScaredVectorLeft1.push_back(sprite);
    }    for (int i = 0; i < 2; i++)
    {
        sprite.load("images/Background.png");
        sprite.cropFrom(sprite, 521 + 16 * i, 64, 16, 16);
        NotScaredVectorUp1.push_back(sprite);
    }    for (int i = 0; i < 2; i++)
    {
        sprite.load("images/Background.png");
        sprite.cropFrom(sprite, 553 + 16 * i, 64, 16, 16);
        NotScaredVectorDown1.push_back(sprite);
    } 
        break;
    }
    Scared = new Animation(5, ScaredVector);
    NotScaredUP1 = new Animation(5, NotScaredVectorUp1);
    NotScaredDown1= new Animation(5, NotScaredVectorDown1);
    NotScaredLeft1 = new Animation(5, NotScaredVectorLeft1);
    NotScaredRight1 = new Animation(5, NotScaredVectorRight1);

    NotScared = new Animation(1,NotScaredVector);
    this->em = em;
}
 void GhostSpawner::render()
{   
    if(getMortal() == false)
    {
        if(faze1 == UPGhost1){
            NotScaredUP1->getCurrentFrame().draw(x, y, width, height);
        }else if(faze1 == DOWNGhost1){
            NotScaredDown1->getCurrentFrame().draw(x, y, width, height);
        }else if(faze1 == LEFTGhost1){
            NotScaredLeft1->getCurrentFrame().draw(x, y, width, height);
        }else if(faze1 == RIGHTGhost1){
            NotScaredRight1->getCurrentFrame().draw(x, y, width, height);
        }
    }
    else
    {
        if(faze1 == UPGhost1){
            Scared->getCurrentFrame().draw(x, y, width, height);
        }else if(faze1 == DOWNGhost1){
            Scared->getCurrentFrame().draw(x, y, width, height);
        }else if(faze1 == LEFTGhost1){
            Scared->getCurrentFrame().draw(x, y, width, height);
        }else if(faze1 == RIGHTGhost1){
            Scared->getCurrentFrame().draw(x, y, width, height);
        }
    }
}


void GhostSpawner::tick()
{
    canghostmove1 = true;
    checkCollisions1();
    if (canghostmove1)
    {
        if (faze1 == DOWNGhost1)
        {
            y += speedghost1;
            if(getMortal()== false)
            {
            NotScared->tick();
            }else
            {
                Scared->tick();
            }
        }
        else if (faze1 == UPGhost1)
        {
            y -= speedghost1;
            if(getMortal()== false)
            {
            NotScared->tick();
            }else
            {
                Scared->tick();
            }
        }
        else if (faze1 == LEFTGhost1)
        {
            x -= speedghost1;
            if(getMortal()== false)
            {
            NotScared->tick();
            }else
            {
                Scared->tick();
            }
        }
        else if (faze1 == RIGHTGhost1)
        {
            x += speedghost1;
            if(getMortal()== false)
            {
            NotScared->tick();
            }else
            {
                Scared->tick();
            }
        }
    }
}


void GhostSpawner::checkCollisions1()
{
    for (Block* block: em->blocks)
    {
        switch (faze1)
        {
        case UPGhost1:
            if (this->getBounds(x, y - speedghost1).intersects(block->getBounds()))
            {
                int faze1 = round(ofRandom(0,3));
                if(count1 == 0) faze1 = 3;
                count1 += 1;
                canghostmove1 = false;
                if (faze1 != 0)
                {
                    switch (faze1)
                    {
                    case 0:
                        setfaze1(UPGhost1);
                        break;
                    case 1:
                        setfaze1(DOWNGhost1);
                        canghostmove1 = false;
                        break;
                    case 2:
                        setfaze1(LEFTGhost1);
                        break;
                    case 3:
                        setfaze1(RIGHTGhost1);
                        break;
                    default:
                        break;
                    }
                }
            }
            break;
        case DOWNGhost1:
            if (this->getBounds(x, y+speedghost1).intersects(block->getBounds()))
            {
                int faze1 = round(ofRandom(0,3));
                canghostmove1 = false;
                if (faze1 != 1)
                {
                    switch (faze1)
                    {
                    case 0:
                        setfaze1(UPGhost1);
                        canghostmove1 = false;
                        break;
                    case 1:
                        setfaze1(DOWNGhost1);
                        canghostmove1 = false;
                        break;
                    case 2:
                        setfaze1(LEFTGhost1);
                        break;
                    case 3:
                        setfaze1(RIGHTGhost1);
                        break;

                    default:
                        break;
                    }
                }
            }
            break;
        case LEFTGhost1:
            if (this->getBounds(x-speedghost1, y).intersects(block->getBounds()))
            {
                int faze1 = round(ofRandom(0,3));
                canghostmove1 = false;
                if (faze1 != 2)
                {
                    switch (faze1)
                    {
                    case 0:
                        setfaze1(UPGhost1);
                        break;
                    case 1:
                        setfaze1(DOWNGhost1);
                        break;
                    case 2:
                        setfaze1(LEFTGhost1);
                        canghostmove1 = false;
                        break;
                    case 3:
                        setfaze1(RIGHTGhost1);
                        canghostmove1 = false;
                        break;
                    default:
                        break;
                    }
                }
            }
            break;
        case RIGHTGhost1:
            if (this->getBounds(x + speedghost1, y).intersects(block->getBounds()))
            {
                int faze1= round(ofRandom(0,3));
                canghostmove1 = false;
                if (faze1 != 3)
                {
                    switch (faze1)
                    {
                    case 0:
                        setfaze1(UPGhost1);
                        break;
                    case 1:
                        setfaze1(DOWNGhost1);
                        break;
                    case 2:
                        setfaze1(LEFTGhost1);
                        canghostmove1 = false;
                        break;
                    case 3:
                        setfaze1(RIGHTGhost1);
                        canghostmove1 = false;
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