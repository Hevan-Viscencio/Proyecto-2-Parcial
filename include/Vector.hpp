#pragma once

class Vector
{
private:
    int direccion_x;
    int direccion_y;
    int x;
    int y;

public:
    Vector()
    {
        this->x = 0;
        this->y = 0;
        this->direccion_x = 1;
        this->direccion_y = 1;
    }
    Vector(int x, int y)
    {
        this->x = x;
        this->y = y;
        this->direccion_x = 1;
        this->direccion_y = 1;
    }
    void CambiarDireccionX()
    {
        this->direccion_x *= -1;
    }
    void CambiarDireccionY()
    {
        this->direccion_y *= -1;
    }
    void DesplazarX(unsigned int x)
    {
        this->x += x * this->direccion_x;
    }
    void DesplazarY(unsigned int y)
    {
        this->y += y;
    }
    int LeerX()
    {
        return this->x;
    }
    int LeerY()
    {
        return this->y;
    }

    ~Vector() {}
};
