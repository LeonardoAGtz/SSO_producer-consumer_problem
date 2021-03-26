#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include <windows.h>

using namespace std;

class Nodo
{
public:
    string dato;
    int pos;
    Nodo *siguiente = nullptr;
    Nodo *anterior = nullptr;
};

class Lista
{
    Nodo *primero;
    Nodo *ultimo;
    Nodo *last_productor;
    Nodo *last_consumidor;
public:
    Lista();
    void crearNodo(string dato, int pos);
    bool lista_vacia();
    void imprimir();
    void consumidor(int cantidad);
    void productor(int cantidad);
    int productos();
    int stock();
};

#endif // LISTA_H
