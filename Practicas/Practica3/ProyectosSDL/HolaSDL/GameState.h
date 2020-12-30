#pragma once
#include <list>
#include "GameObject.h"
#include "EventHandler.h"
class App;
class GameState
{
public:
	GameState(App* app):app_(app) {};
	virtual ~GameState();
	
	virtual void render();
	virtual void update();
	virtual void handleEvents(SDL_Event& event);


	void addGameObject(GameObject* go);
	void addEventHandler(EventHandler* ev);

	void deleteGameObject(std::list<GameObject*>::iterator go) { gObjectsToErase_.push_back(go); }

protected:
	App* app_;

	std::list<GameObject*> gObjects_;
	std::list<EventHandler*> hEvents_;
	std::list<std::list<GameObject*>::iterator> gObjectsToErase_;
};

