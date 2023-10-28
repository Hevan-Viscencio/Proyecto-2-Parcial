#pragma once
#include <Vector.hpp>
#include <Dibujo.hpp>
#include <Actualizable.hpp>

class Asteroide : public Dibujo, public Actualizable
{
private:
    //Vector posicion;

public:
    Asteroide() : Dibujo("asteroide")
    {
        this->posicion = Vector();
    }


    Asteroide(int x,int y):Dibujo("asteroide"){
        this->posicion.DesplazarX(x);
        this->posicion.DesplazarY(y);
    }



    void Actualizar()
    {
        this->posicion.DesplazarX(1);
        this->posicion.DesplazarY(0);
    }
    ~Asteroide()
    {
    }
};