#include "lista.h"
#include <conio.h>

using namespace std;
Lista lista;
int random_turno();
int random_entrada();
char tecla;


int main()
{
    for (int i = 0; i < 30; ++i) {
        string data = "-";
        int pos = i+1;
        lista.crearNodo(data, pos);
    }


    cout << "Solucion programada por Leonardo Aranda Gutierrez 217761528" << endl << endl;
    cout << "CENTRO UNIVERSITARIO DE CIENCIAS EXACTAS E INGENIERIAS" << endl;
    cout << "INGENIERIA INFORMATICA" << endl;
    cout << "SISTEMAS OPERATIVOS." << endl <<endl;
    cout << "ESTE PROGRAMA REPRESENTA EL PROBLEMA PRODUCTO/CONSUMIDOR" << endl;
    cout << "PARA FINALIZAR PRESIONE LA TECLA 'ESC'" << endl;
    cout << "Presione cualquier tecla para continuar..." << endl << endl;

    system("pause");

    while (true) {
        if (kbhit() == 1 and (tecla = getch()) == 27){
            break;
        }else {
            int value = random_turno();

            lista.imprimir();

            if (value % 2 == 0) { //Si el número de entrada es par y no está lleno entra productor.
                SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),8);
                cout <<"El consumidor esta dormido" << endl;
                SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7);
                lista.productor(random_entrada());
                cout << endl;
            }else if (value % 2 != 0){ //Si el número de entrada es impar y no esta vacio, entra el consumidor.
                SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),8);
                cout << "El productor esta dormido" << endl;
                SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7);
                lista.consumidor(random_entrada());
                cout << endl;
            }

            Sleep(1800);
        }
    }

    cout << endl;
    return 0;
}

int random_turno(){
    int value = rand() % 10 + 1;
    return value;
}

int random_entrada(){
    int value = rand() % (10-3+1) +3;
    return value;
}
