#include "MenuState.h"

MenuState::MenuState() {
	background.load("images/1726777.jpg");
	startButton = new Button(ofGetWidth()/2, ofGetHeight()/2, 64, 50, "Start");
}

//More or less the same as update
void MenuState::tick() {
	startButton->tick();
	if(startButton->wasPressed()){
		intermis.load("pacman_intermis.mp3");
		intermis.play();
		setNextState("Game");
		setFinished(true);

	}
}
void MenuState::render() {
	ofSetColor(255);
	background.draw(0,0,1024,768);
	startButton->render();

}

void MenuState::keyPressed(int key){
	
}

void MenuState::mousePressed(int x, int y, int button){
	startButton->mousePressed(x, y);
}

void MenuState::reset(){

	setFinished(false);
	setNextState("");
	startButton->reset();
}