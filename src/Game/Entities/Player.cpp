#include "Player.h"
#include "EntityManager.h"
#include "Dot.h"
#include "BigDot.h"
#include "Ghost.h"
#include "GhostSpawner.h"

Player::Player(int x, int y, int width, int height, EntityManager* em) : Entity(x, y, width, height){
    sprite.load("images/pacman.png");
    down.cropFrom(sprite, 0, 48, 16, 16);
    up.cropFrom(sprite, 0, 32, 16, 16);
    left.cropFrom(sprite, 0, 16, 16, 16);
    right.cropFrom(sprite, 0, 0, 16, 16);
    
    vector<ofImage> downAnimframes;
    vector<ofImage> upAnimframes;
    vector<ofImage> leftAnimframes;
    vector<ofImage> rightAnimframes;
    ofImage temp;
    for(int i=0; i<3; i++){
        temp.cropFrom(sprite, i*16, 48, 16, 16);
        downAnimframes.push_back(temp);
    }
    for(int i=0; i<3; i++){
        temp.cropFrom(sprite, i*16, 32, 16, 16);
        upAnimframes.push_back(temp);
    }
    for(int i=0; i<3; i++){
        temp.cropFrom(sprite, i*16, 16, 16, 16);
        leftAnimframes.push_back(temp);
    }
    for(int i=0; i<3; i++){
        temp.cropFrom(sprite, i*16, 0, 16, 16);
        rightAnimframes.push_back(temp);
    }
    walkDown = new Animation(1,downAnimframes);
    walkUp = new Animation(1,upAnimframes);
    walkLeft = new Animation(1,leftAnimframes);
    walkRight = new Animation(1,rightAnimframes);

    this->em = em;
    
}

void Player::die(){
    if(this->health > 0) {
        this->health -= 100;
        this->x = 312;
        this->y = 624;
        canMove = true;
        dead.load("pacmandying.mp3");
        dead.play();
    }
}

void Player::tick(){
    canMove = true;
    checkCollisions();
    if(canMove){
        if(facing == UP){
            y-= speed;
            walkUp->tick();
        }else if(facing == DOWN){
            y+=speed;
            walkDown->tick();
        }else if(facing == LEFT){
            x-=speed;
            walkLeft->tick();
        }else if(facing == RIGHT){
            x+=speed;
            walkRight->tick();
        }
    }
    if(getHealth() == 0){
        mySound2.stop();
    }
}

void Player::render(){
    if (Player::getHealth() <= 500)/*This switch is for show the player the life of pacman
    and if pacman has more than five lifes is representated by a plus sign*/
    {
        switch (Player::getHealth())
        {
        case 500:
            ofSetColor(255, 255, 0);
            ofDrawCircle(800, 15, 10);
            ofDrawCircle(825, 15, 10);
            ofDrawCircle(850, 15, 10);
            ofDrawCircle(875, 15, 10);
            ofDrawCircle(900, 15, 10);
            break;
        case 400:
            ofSetColor(255, 255, 0);
            ofDrawCircle(800, 15, 10);
            ofDrawCircle(825, 15, 10);
            ofDrawCircle(850, 15, 10);
            ofDrawCircle(875, 15, 10);
            break;
        case 300:
            ofSetColor(255, 255, 0);
            ofDrawCircle(800, 15, 10);
            ofDrawCircle(825, 15, 10);
            ofDrawCircle(850, 15, 10);
            break;
        case 200:
            ofSetColor(255, 255, 0);
            ofDrawCircle(800, 15, 10);
            ofDrawCircle(825, 15, 10);
            break;
        case 100:
            ofSetColor(255, 255, 0);
            ofDrawCircle(800, 15, 10);
            break;
        }
    }
    else
    {
        ofSetColor(255, 255, 0);
        ofDrawCircle(800, 15, 10);
        ofDrawCircle(825, 15, 10);
        ofDrawCircle(850, 15, 10);
        ofDrawCircle(875, 15, 10);
        ofDrawCircle(900, 15, 10);
        ofSetColor(255,255,0);
        ofDrawLine(920,10,920,20);
        ofDrawLine(915,15,925,15);
    }
    ofSetColor(255);
    ofDrawBitmapString("Score:" + to_string(Player::getScore()),50,20);
    ofDrawBitmapString("Health:",730,20);
    ofSetColor(256,256,256);
    // ofDrawRectangle(getBounds());
    if(facing == UP){
        walkUp->getCurrentFrame().draw(x, y, width, height);
        
    }else if(facing == DOWN){
        walkDown->getCurrentFrame().draw(x, y, width, height);
    }else if(facing == LEFT){
        walkLeft->getCurrentFrame().draw(x, y, width, height);
    }else if(facing == RIGHT){
        walkRight->getCurrentFrame().draw(x, y, width, height);
    }
}

void Player::keyPressed(int key)
{
    switch(key)
    {
        case 'w':
            setFacing(UP);
            break;
        case 's':
            setFacing(DOWN);
            break;
        case 'a':
            setFacing(LEFT);
            break;
        case 'd':
            setFacing(RIGHT);
            break;
        case 'n':
            if (Player::getHealth() > 0 )
            {
                health -= 100; // Increase health by 1 when m is prissed
            }
            low.load("pacman_low.mp3");
            low.play();
            break;
        case 'm':
            health += 100; // Increase health by 1 when m is prissed
            life.load("pacman_life.mp3");
            life.play();
            break;
        case 'p':
            mySound2.load("super-mario-bros-nes-music-star-theme-cut-mp3.mp3");//for test ghost death
            mySound2.play();
            break;
        case 'g':
            GhostSpawner* en = new GhostSpawner(504, 368, width, height, sprite, color, em);
            em->entities.push_back(en);
            if(color == 4) color = 0;
            color += 1;
            break;
            //Tengo que añadir el ghost spawnmer 
    }
}

void Player::keyReleased(int key){
    if(key == 'w' || key =='s' || key == 'a' || key == 'd'){
        walking = false;
    }
}
void Player::mousePressed(int x, int y, int button){

}

void Player::setFacing(FACING facing){
    this->facing = facing;
}

void Player::checkCollisions(){
    for(Block* block: em->blocks){
        switch(facing){
            case UP:
                if(this->getBounds(x, y-speed).intersects(block->getBounds())){
                    canMove = false;
                }
                break;
            case DOWN:
                if(this->getBounds(x, y+speed).intersects(block->getBounds())){
                    canMove = false;
                }
                break;
            case LEFT:
                if(this->getBounds(x-speed, y).intersects(block->getBounds())){
                    canMove = false;
                }
                break;
            case RIGHT:
                if(this->getBounds(x+speed, y).intersects(block->getBounds())){
                    canMove = false;
                }
                break;
        }
    }
    for(Entity* entity:em->entities){
        if(collides(entity)){
            if(dynamic_cast<Dot*>(entity))
            {
                entity->remove = true;
                setScore(Player::getScore() + 5);
                mySound.setMultiPlay(true);
                mySound.setSpeed(1.2);
                mySound.load("pacman_chomp.wav");
                mySound.play();
            }
            if(dynamic_cast<BigDot*>(entity))
            {
                entity->remove = true;
                setScore(Player::getScore() + 25);
                mySound.load("pacman_eatfruit.wav");
                mySound.play();
                mySound2.load("super-mario-bros-nes-music-star-theme-cut-mp3.mp3");
                mySound2.play();
                        //Timer to make ghosts edible
                        //Make ghosts edible
            }
            if(dynamic_cast<Ghost*>(entity)) // Ghost collision
            {
                if(mySound2.isPlaying())
                {
                    entity->remove = true;
                    setScore(Player::getScore() + 50);
                    GhostSpawner* en = new GhostSpawner(504, 368, width, height, sprite, color, em);
                    em->entities.push_back(en);
                    if(color == 4) color = 0;
                    color += 1;
                    dynamic_cast<Ghost*>(entity)->setMortal();
                    ghost.load("pacman_ghost.mp3");
                    ghost.play();
                }
                else die();
            }
                // Allow pacman to eat ghost on collision during edible phase
                 //TIMER TO MAKE GHOSTS RESPAWN AFTER COLLISION DURING EDIBLE PHASE 

        }
    }
    
}