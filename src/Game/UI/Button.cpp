#include "Button.h"
Button::Button(){
   this->xPos = ofGetWidth()/2;
    this->yPos = ofGetHeight()/2;
    this->width = 128;
    this->height = 40; 
}
Button::Button(int xPos, int yPos, int width, int height, string buttonText){
    this->xPos = xPos;
    this->yPos = yPos;
    this->width = width;
    this->height = height;
    this->buttonText = buttonText;
}

void Button::reset(){
    pressedCounter = -1;
    pressed = false;
}
void Button::tick(){
    pressedCounter--;
    if(pressedCounter == 0){
        pressed = false;
        pressedCounter = -1;
    }

}

void Button::mousePressed(int x, int y){
    if(xPos + width >= x && x >= xPos &&  yPos + height >= y && y >= yPos){
        pressed = true;
        pressedCounter = 10;
    }
    else {
        pressed = false;
    }
}

void Button::render(){
    ofFill();
    ofSetColor(255, 113, 181);
    ofBeginShape();
    ofDrawRectangle(975/2, 768/2, 50, 150, 50);
    ofEndShape();
    ofSetColor(0,0,0);
    ofDrawBitmapString(buttonText, xPos+width/2, yPos+height/2);
}

bool Button::wasPressed(){
    return pressed;
}