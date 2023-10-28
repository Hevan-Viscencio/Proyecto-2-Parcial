#pragma once
class HitBox
{
protected:
    unsigned int x;
    unsigned int y;
    unsigned int dx;
    unsigned int dy;

public:
    HitBox() : HitBox(0, 0, 0, 0) {}
    HitBox(unsigned int x, unsigned int y, unsigned int dx, unsigned int dy)
    {
        this->x = x;
        this->y = y;
        this->dx = dx;
        this->dy = dy;
    }
    ~HitBox() {}

    bool DetectarColision(HitBox* hitbox)
    {
        int der1 = this->x + this->dx;
        int der2 = hitbox->x + hitbox->dx;

        int izq1 = this->x;
        int izq2 = hitbox->x;

        if(der1 > izq2 )
            return true;
        if(izq1 <der2 )
            return true;

        // Calculos para hitbox
        return false;
    }
};
