#include "lista.h"

Lista::Lista()//LISTO
{
    primero = ultimo = nullptr;
}

void Lista::crearNodo(string dato, int pos)//LISTO
{
    Nodo *nuevo = new Nodo;

    if (lista_vacia()) {
        nuevo->dato = dato;
        nuevo->pos = pos;
        primero = nuevo;
        ultimo = nuevo;
        last_productor = primero;
        last_consumidor = primero;
    }else {
        nuevo->dato = dato;
        nuevo->pos = pos;
        nuevo->anterior = ultimo;
        ultimo->siguiente = nuevo;
        ultimo = nuevo;
        nuevo->siguiente = primero;
    }
}

bool Lista::lista_vacia()//LISTO
{
    return primero == nullptr;
}

void Lista::imprimir()//LISTO
{
    Nodo *aux(primero);

    for (int i = 0; i < 30; ++i) {
        if (aux->dato == "-") {
            SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7);
            cout << aux->dato << " ";
            SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7);

        }else if (aux->dato == "*") {
            SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),10);
            cout << aux->dato << " ";
            SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7);
        }
        if (aux->pos > 9) {
            cout << " ";
        }
        aux = aux->siguiente;
    }
    cout << endl;
    for (int i = 0; i < 30; ++i) {
        cout << aux->pos << " ";
        aux = aux->siguiente;
    }
    cout << endl << endl;
}

void Lista::consumidor(int cantidad)
{
    Nodo *aux(last_consumidor);
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),6);
    cout << "El consumidor intenta trabajar" << endl;
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),8);

    if (productos() < cantidad) { //Se verifica que haya stock suficiente para consumir.
        SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),4);
        cout << "El consumidor intenta consumir " << cantidad << " productos" << endl;
        cout << "Hay menos productos de los suficientes para consumir" << endl;
        SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7);
    }else{
        SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),9);
        cout << "El consumidor esta trabajando" << endl;
        cout << "El consumidor tomara " << cantidad << " productos" << endl;
        SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7);
        while (cantidad > 0) { //Mientras queden por consumir
            if (aux->dato == "*") {// si el espacio tiene el producto
                aux->dato = "-"; //se consume
                cantidad--; //disminuye la cantidad por consumir
                aux = aux->siguiente; //nos movemos al siguiente nodo en la lista.
                last_consumidor = aux; //actualizacmos el ultimo
            }
            else if (aux->dato == "-") { // su el espacio está vacio
                aux = aux->siguiente; //nos movemos para encontrar producto.
            }
        }
    }
}

void Lista::productor(int cantidad)
{
    Nodo *aux(last_productor);
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),6);
    cout << "El productor intenta trabajar" <<endl;
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),8);

    if (stock() < cantidad) { //se verifica que haya espacio disponible para el stock.
        SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),4);
        cout << "El productor intenta producir " << cantidad << " productos" << endl;
        cout << "No hay espacio suficiente para almacenar la produccion" << endl;
        SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7);

    }else{
        SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),9);
        cout << "El productor esta trabajando" << endl;
        cout << "El productor almacenara " << cantidad << " productos." << endl;
        SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7);
        while (cantidad > 0) { //Mientras aun queden articulos por almacenar
            if (aux->dato == "-") { //si el espacio en el nodo actual es vacio
                aux->dato = "*"; //almacenamos un producto ahi.
                cantidad--; //disminuimos la cantidad por almacenar
                aux = aux->siguiente; //nos movemos al siguiente nodo en la lista.
                last_productor = aux; //actualizamos el ultimo.
            }
            else if (aux->dato == "*") { // si el espacio en el nodo esta ocupado
                aux = aux->siguiente; //nos movemos al siguiente nodo en la lista.
            }
        }
    }
}

int Lista::productos()
{
    Nodo *aux(primero);
    int nodos = 0;
    int size = 0;
    while (nodos < 30){
        if (aux->dato == "*") {
            size++;
        }
        aux = aux->siguiente;
        nodos++;
    }

    return size;
}

int Lista::stock()
{
    Nodo *aux(primero);
    int nodos = 0;
    int size = 0;

     while (nodos < 30){
        if (aux->dato == "-") {
            size++;
        }
        aux = aux->siguiente;
        nodos++;
    }

    return size;
}
