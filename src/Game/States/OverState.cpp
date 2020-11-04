#include "OverState.h"

OverState::OverState() {
	background.load("images/pacdead.jpg");
	startButton = new Button(ofGetWidth()/2, ofGetHeight()/2, 64, 50, "Wanna play again?");
}

void OverState::tick() {
	startButton->tick();
	if(startButton->wasPressed()){
		setNextState("Game");
		setFinished(true);
	}
}

void OverState::setFinalScore(int score){
    this->score = score;
}

void OverState::render() {
	ofSetColor(255);
	background.draw(0,0,1024,768);
	startButton->render();
	ofSetColor(255, 255, 255);
    ofDrawBitmapString("Final Score: " + to_string(score),50 , 20);
}

void OverState::keyPressed(int key){

}

void OverState::mousePressed(int x, int y, int button){
	startButton->mousePressed(x, y);
}

void OverState::reset(){
	setFinished(false);
	setNextState("");
	startButton->reset();
}

