#pragma once
#include <fstream>
#include <curses.h>
#include <string>
#include <Vector.hpp>
using namespace std;

class Dibujo
{
private:
    fstream archivo;
    bool is_open;
    string directorio;

protected:
    Vector posicion;

public:
    Dibujo(int x, int y, string recurso)
    {
        this->directorio = "./data/" + recurso + ".txt";
        this->is_open = false;
        this->archivo.open(this->directorio, ios::in);
        this->posicion = Vector(x, y);
    }
    Dibujo(string recurso) : Dibujo(0, 0, recurso)
    {
    }

    void Dibujar()
    {
        if (archivo.is_open())
        {
            std::string line;
            move(
                this->posicion.LeerY(),
                this->posicion.LeerX());

            while (std::getline(archivo, line))
            {

                // printw(line.c_str()); // Output each line to the console
                int y;
                y = getcury(stdscr);
                mvaddstr(
                    y + 1,
                    this->posicion.LeerX(),
                    line.c_str());
            }
            archivo.clear();
            archivo.seekg(0);
        }
    }
    ~Dibujo()
    {
        archivo.close();
    }
};
