#include "Ghost.h"
#include "Block.h"
Ghost::Ghost(int x, int y, int width, int height, ofImage spriteSheet, EntityManager* em) : Entity(x, y, width, height)
{
    sprite.load("images/Background.png");
    sprite.cropFrom(sprite, 457, 95, 16, 16);
    vector<ofImage> NotScaredVectorLeft;
    vector<ofImage> NotScaredVectorUp;
    vector<ofImage> NotScaredVectorDown;
    vector<ofImage> NotScaredVectorRight;
    for (int i = 0; i < 7; i++)
    {
        sprite.load("images/Background.png");
        sprite.cropFrom(sprite, 457 + 16 * i, 64, 16, 16);
        NotScaredVectorRight.push_back(sprite);
    }
        for (int i = 0; i < 2; i++)
    {
        sprite.load("images/Background.png");
        sprite.cropFrom(sprite, 489 + 16 * i, 64, 16, 16);
        NotScaredVectorLeft.push_back(sprite);
    }    for (int i = 0; i < 2; i++)
    {
        sprite.load("images/Background.png");
        sprite.cropFrom(sprite, 521 + 16 * i, 64, 16, 16);
        NotScaredVectorUp.push_back(sprite);
    }    for (int i = 0; i < 2; i++)
    {
        sprite.load("images/Background.png");
        sprite.cropFrom(sprite, 553 + 16 * i, 64, 16, 16);
        NotScaredVectorDown.push_back(sprite);
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
    NotScaredUP = new Animation(5, NotScaredVectorUp);
    NotScaredDown= new Animation(5, NotScaredVectorDown);
    NotScaredLeft = new Animation(5, NotScaredVectorLeft);
    NotScaredRight = new Animation(5, NotScaredVectorRight);
}

 void Ghost::render()
{   
    if(getMortal() == false)
    {
        if(faze == UPGhost){
            NotScaredUP->getCurrentFrame().draw(x, y, width, height);
        }else if(faze == DOWNGhost){
            NotScaredDown->getCurrentFrame().draw(x, y, width, height);
        }else if(faze == LEFTGhost){
            NotScaredLeft->getCurrentFrame().draw(x, y, width, height);
        }else if(faze == RIGHTGhost){
            NotScaredRight->getCurrentFrame().draw(x, y, width, height);
        }
    }
    else
    {
        if(faze == UPGhost){
            Scared->getCurrentFrame().draw(x, y, width, height);
        }else if(faze == DOWNGhost){
            Scared->getCurrentFrame().draw(x, y, width, height);
        }else if(faze == LEFTGhost){
            Scared->getCurrentFrame().draw(x, y, width, height);
        }else if(faze == RIGHTGhost){
            Scared->getCurrentFrame().draw(x, y, width, height);
        }
    }
}

void Ghost::tick()
{
    canghostmove = true;
    //checkCollisions();
    if (canghostmove)
    {
        if (faze == DOWNGhost)
        {
            y += speedghost;
            NotScaredDown->tick();
        }
        else if (faze == UPGhost)
        {
            y -= speedghost;
            NotScaredUP->tick();
        }
        else if (faze == LEFTGhost)
        {
            x -= speedghost;
            NotScaredLeft->tick();
        }
        else if (faze == RIGHTGhost)
        {
            x += speedghost;
            NotScaredRight->tick();
        }
    }
}

void Ghost::checkCollisions(){
    for(Block* blockis: em->blocks){
        switch(faze){
            case UPGhost:
                if(this->getBounds(x, y-speedghost).intersects(blockis->getBounds())){
                    canghostmove = false;
                }
                break;
            case DOWNGhost:
                if(this->getBounds(x, y+speedghost).intersects(blockis->getBounds())){
                    canghostmove = false;
                }
                break;
            case LEFTGhost:
                if(this->getBounds(x-speedghost, y).intersects(blockis->getBounds())){
                    canghostmove = false;
                }
                break;
            case RIGHTGhost:
                if(this->getBounds(x+speedghost, y).intersects(blockis->getBounds())){
                    canghostmove = false;
                }
                break;
        }
    }
}





// void Ghost::checkCollisions()
// {
//     for (Block* block: em->blocks)
//     {
//         switch (faze)
//         {
//         case UPGhost:
//             if (this->getBounds(x, y - speedghost).intersects(block->getBounds()))
//             {
//                 int faze = round(ofRandom(0,3));
//                 canghostmove = false;
//                 if (faze != 0)
//                 {
//                     switch (faze)
//                     {
//                     case 0:
//                         setfaze(UPGhost);
//                         break;
//                     case 1:
//                         setfaze(DOWNGhost);
//                         canghostmove = false;
//                         break;
//                     case 2:
//                         setfaze(LEFTGhost);
//                         break;
//                     case 3:
//                         setfaze(RIGHTGhost);
//                         break;
//                     default:
//                         break;
//                     }
//                 }
//             }
//             break;
//         case DOWNGhost:
//             if (this->getBounds(x, y+speedghost).intersects(block->getBounds()))
//             {
//                 int faze = round(ofRandom(0,3));
//                 canghostmove = false;
//                 if (faze != 1)
//                 {
//                     switch (faze)
//                     {
//                     case 0:
//                         setfaze(UPGhost);
//                         canghostmove = false;
//                         break;
//                     case 1:
//                         setfaze(DOWNGhost);
//                         canghostmove = false;
//                         break;
//                     case 2:
//                         setfaze(LEFTGhost);
//                         break;
//                     case 3:
//                         setfaze(RIGHTGhost);
//                         break;

//                     default:
//                         break;
//                     }
//                 }
//             }
//             break;
//         case LEFTGhost:
//             if (this->getBounds(x-speedghost, y).intersects(block->getBounds()))
//             {
//                 int faze = round(ofRandom(0,3));
//                 canghostmove = false;
//                 if (faze != 2)
//                 {
//                     switch (faze)
//                     {
//                     case 0:
//                         setfaze(UPGhost);
//                         break;
//                     case 1:
//                         setfaze(DOWNGhost);
//                         break;
//                     case 2:
//                         setfaze(LEFTGhost);
//                         canghostmove = false;
//                         break;
//                     case 3:
//                         setfaze(RIGHTGhost);
//                         canghostmove = false;
//                         break;
//                     default:
//                         break;
//                     }
//                 }
//             }
//             break;
//         case RIGHTGhost:
//             if (this->getBounds(x + speedghost, y).intersects(block->getBounds()))
//             {
//                 int faze= round(ofRandom(0,3));
//                 canghostmove = false;
//                 if (faze != 3)
//                 {
//                     switch (faze)
//                     {
//                     case 0:
//                         setfaze(UPGhost);
//                         break;
//                     case 1:
//                         setfaze(DOWNGhost);
//                         break;
//                     case 2:
//                         setfaze(LEFTGhost);
//                         canghostmove = false;
//                         break;
//                     case 3:
//                         setfaze(RIGHTGhost);
//                         canghostmove = false;
//                         break;
//                     default:
//                         break;
//                     }
//                 }
//             }
//             break;
//         }
//     }
// }