#pragma once
#include "Ghost.h"

class Game;
// La edad determinará si se puede reproducir, tiene que esperar o tiene que morir
enum Age{CHILD, ADULT, QUARANTINE}; //edad

class SmartGhost :
	public Ghost
{
public:
    SmartGhost() : Ghost() {	throw "SmartFantasma nulo (Not so smart now)"; }
	SmartGhost(Point2D pos, double speed, double width, double height, Texture* texture, Game* game, int color);
	virtual ~SmartGhost() {};
	
	void render();
	void update();
	void handleState(); //cambia la fase del fantasma si es necesario
	inline Age getAge() { return age_; } //deuelve la edad

private:
	Age age_; //edad del fantasma
	int time_; //tiempo de fase
	int reproduction_time; //cooldwn para reproducirse

};

