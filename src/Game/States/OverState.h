#pragma once

#include "State.h"
#include "Button.h"

class OverState : public State {
private:
	ofImage img1;
	Button *startButton;
	ofImage background;

public:
	int score;
	
	OverState();
    void setFinalScore(int finalScore);
	void tick();
	void render();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void reset();
	int getScore();
};
