#include <Ventana.hpp>
#include <Nave.hpp>
#include <Asteroide.hpp>
#include <Actualizable.hpp>
#include <list>
#include <iostream>
#include <string.h>
#include<curses.h>
#include<Shoot.hpp>
#include<Space.hpp>


using namespace std;

int main(int argc, char const *argv[])
{

    Nave * nave = new Nave(65,0);
    Space * space = new Space(2,0);
    Asteroide *asteroide = new Asteroide(0,10);
    Asteroide *asteroide2 = new Asteroide(50,0);
    Asteroide *asteroide3 = new Asteroide(20,20);
    Ventana* ventana = new Ventana();

    list<Dibujo*> dibujos;
    dibujos.push_back(space);
    dibujos.push_back(nave);
    dibujos.push_back(asteroide);
    dibujos.push_back(asteroide2);
    dibujos.push_back(asteroide3);
    


    list<Actualizable*> actualizables;
    actualizables.push_back(nave);
    actualizables.push_back(asteroide);
    actualizables.push_back(asteroide2);
    actualizables.push_back(asteroide3);


        while (!ventana->DeboCerrar())
    {
        int key =getch();
        if(key == 'a' || key == KEY_LEFT){
            nave->Avanzara();

        }
        if(key == 'd' || key == KEY_RIGHT){
            nave->Avanzard();
        }  
        if(key == 'w' || key == KEY_UP){
            nave->Avanzarw();
        }  
        if(key == 's' || key == KEY_DOWN){
            nave->Avanzars();
        }  
        if(key == ' '){
            Shoot*p = new Shoot(nave->LeerPosicion());
            dibujos.push_back(p);
            actualizables.push_back(p);
        }

        //if(nave->DetectarColision(nave)){
          //  break;
        //}
        ventana->Dibujar(dibujos);
        ventana->Actualizar(actualizables);
    }

    return 0;
}