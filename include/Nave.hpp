#pragma once
#include <Vector.hpp>
#include <Dibujo.hpp>
#include <Actualizable.hpp>
#include <HitBox.hpp>

class Nave : public Dibujo, public Actualizable, public HitBox
{
private:
    // Vector posicion;

public:
    Nave() : Dibujo("ship"), 
        HitBox(
            this->posicion.LeerX(),
            this->posicion.LeerY(),
            12,4)
    {
        this->posicion = Vector();
    }

    Nave(int x, int y) : Dibujo("ship"),HitBox(
            this->posicion.LeerX(),
            this->posicion.LeerY(),
            12,4)
    {
        this->posicion.DesplazarX(x);
        this->posicion.DesplazarY(y);
    }

    void Actualizar()
    {
        this->x= posicion.LeerX();
        this->y= posicion.LeerY();
    }
    void Avanzard()
    {
        this->posicion.DesplazarX(1);
    }
    void Avanzara()
    {
        this->posicion.DesplazarX(-1);
    }
    void Avanzarw()
    {
        this->posicion.DesplazarY(-1);
    }
    void Avanzars()
    {
        this->posicion.DesplazarY(1);
    }
    void CambiarDireccion()
    {
        this->posicion.CambiarDireccionX();
        this->posicion.CambiarDireccionY();
    }

    Vector LeerPosicion(){
        return this->posicion;
    }
    ~Nave()
    {
    }
};