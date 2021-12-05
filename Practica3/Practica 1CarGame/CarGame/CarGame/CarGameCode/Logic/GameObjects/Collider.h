#ifndef CARGAME_COLLIDER_H
#define CARGAME_COLLIDER_H

class Car;

class Collider {

public:
    virtual bool receiveCarCollision(Car *car){

        return false;
    };
    virtual bool receiveBulletCollision(Car *car){

        return false;
    };
    virtual bool wave(Car *car){

        return false;
    };
    
};

#endif //CARGAME_COLLIDER_H