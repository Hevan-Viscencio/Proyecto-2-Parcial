#pragma once
#include <Vector.hpp>
#include <Dibujo.hpp>
#include <Actualizable.hpp>

class Space : public Dibujo, public Actualizable
{
private:
    // Vector posicion;

public:
    Space() : Dibujo("space")
    {
        this->posicion = Vector();
    }

    Space(int x, int y) : Dibujo("space")
    {
        this->posicion.DesplazarX(x);
    }

    void Actualizar()
    {
        this->posicion.DesplazarX(0);
        this->posicion.DesplazarY(0);
    }
    ~Space()
    {
    }
};