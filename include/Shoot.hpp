#pragma once
#include <Dibujo.hpp>
#include <Actualizable.hpp>
#include <Vector.hpp>

class Shoot : public Dibujo, public Actualizable
{
private:
    int tiempoVida;

public:
    Shoot(Vector posicion) : Dibujo(posicion.LeerX(), posicion.LeerY(), "missile")
    {
        this->tiempoVida = 100;
    }
    ~Shoot() {}
    void Actualizar()
    {
        this->posicion.DesplazarY(-1);
    }
};
