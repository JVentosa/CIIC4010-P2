#pragma once
#include "State.h"
#include "Player.h"
#include "MapBuilder.h"

class GameState: public State{
    public: 
        GameState();
		void reset();
		void tick();
		void render();
		void keyPressed(int key);
		void mousePressed(int x, int y, int button);
		void keyReleased(int key);
		int score;
		int finalScore;
		int getScore();
		
	

	private:
		ofSoundPlayer dying;
		ofImage mapImage;
		Map* map;
};