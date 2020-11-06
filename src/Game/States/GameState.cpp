#include "GameState.h"
#include "Entity.h"

GameState::GameState() {
	mapImage.load("images/map1.png");
	map = MapBuilder().createMap(mapImage);
}
void GameState::tick() {
	if(map->getPlayer()->getHealth() == 0){
		dying.load("pacmandying.mp3");
		dying.play();
		setNextState("GameOver");
		setFinished(true);
		finalScore = map->getPlayer()->getScore();
		map->getPlayer()->setHealth(500);
		map->getPlayer()->setScore(0);
		map = MapBuilder().createMap(mapImage);
	}

	map->tick();
}
int GameState::getScore(){
	return finalScore;
}

void GameState::render() {
	map->render();
}

void GameState::keyPressed(int key){
	map->keyPressed(key);
}

void GameState::mousePressed(int x, int y, int button){
	map->mousePressed(x, y, button);
}

void GameState::keyReleased(int key){
	map->keyReleased(key);
}

void GameState::reset(){
	setFinished(false);
	setNextState("Game");
}