#include "BadObject.h"
#include "../Game.h"
// TODO: add includes

void  BadObject::onEnter(){
    instances += 1;
};

void  BadObject::onDelete(){
    instances -= 1;
};

void BadObject::reset(){
    instances = 0;
};

bool BadObject::toDelete() {
    return !alive||game->isOutOfGame(this);
}

bool BadObject::wave(int value)
{
	this->pos = { pos.getX() + value, pos.getY() };
	return false;
}

int BadObject::instances = 0;

