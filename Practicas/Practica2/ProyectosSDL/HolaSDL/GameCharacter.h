#pragma once
#include "GameObject.h"


enum directions { LEFT, UP, RIGHT, DOWN };		//enum para las posibles direcciones
const Vector2D dirs_[4] = {			//posibles direcciones
	Vector2D(-1,0),		//izquierda
	Vector2D(0,-1),		//arriba
	Vector2D(1,0),		//derecha
	Vector2D(0,1)		//abajo
};
class Game;
class GameCharacter :
    public GameObject
{
public:
    virtual ~GameCharacter();
   
    virtual void render() override;
    virtual void update() override;
	virtual void saveToFile(std::ofstream& file) override;
	virtual void loadFromFile(std::ifstream& file) override;

    inline void resetPos() { pos_ = pos_init; }
	inline Vector2D getPos() { return pos_; }
	inline void setPos(Vector2D pos) { pos_ = pos; }
	inline void setPos(int x, int y) { pos_ = Vector2D(x, y); }

  
protected:
	GameCharacter();
    GameCharacter(Point2D pos, double speed, double width, double height, Texture* texture, Game* game);
   
    Point2D pos_init;	//posicion inicial
    Vector2D dir_;		//direccion actual
	float speed_;		//velocidad
   
};

