#pragma once
#include <curses.h>
#include <unistd.h>
#include <Dibujo.hpp>
#include <Actualizable.hpp>
#include <list>

using namespace std;

class Ventana
{
private:
    int x;
    int y;
    bool cerrar;

public:
    Ventana()
    {
        initscr();

        noecho();
        curs_set(FALSE);

        cbreak();
        timeout(60);
        keypad(stdscr, TRUE);

        getmaxyx(stdscr, x, y);
        cerrar = false;
    }

    void Actualizar(list<Actualizable *> listaActualizables)
    {
        for (auto &&iterator : listaActualizables)
        {
            iterator->Actualizar();
        }
        // usleep(41000);
    }

    void Dibujar(list<Dibujo *> listaDibujos)
    {
        clear();

        box(stdscr, '|', '-');
        for (auto &&dibujo : listaDibujos)
        {
            dibujo->Dibujar();
        }
        refresh();
    }
    bool DeboCerrar()
    {
        return this->cerrar;
    }

    void Cerrar()
    {
        this->cerrar = true;
    }

    ~Ventana()
    {
        keypad(stdscr, FALSE);
        endwin();
    }
};