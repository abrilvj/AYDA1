#include <iostream>
#include <vector>
#include "ejercicios.h"
using namespace std;

int main()
{
    int opcion;
    vector<int> peso = {2, 10, 22, 5, 7};
    vector<int> valor = {1, 8, 23, 8, 10};
    int capacidad = 30;
    vector<Tarea> tareas = {
    {1, 50, 2}, // id, ganancia, limite
    {2, 10, 1},
    {3, 15, 2},
    {4, 30, 1}
    };
    vector<Proceso> procesos = {
    {1, 7}, // id, tiempo
    {2, 5},
    {3, 10},
    {4, 3}
    };
    vector<Actividad> actividades = {
    {1, 1, 4}, // id, inicio, fin
    {2, 4, 8},
    {3, 2, 7},
    {4, 9, 10}
    };

    do {
        cout << "\n TRABAJO PRACTICO GREEDY " << endl;
        cout << "Ingresar nro de ejercicio" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: ejercicio1(capacidad, peso, valor);
                    break;
            case 2: ejercicio2(tareas);
                    break;
            case 3: ejercicio3(procesos);
                    break;
            case 4: ejercicio4(actividades);
                    break;
            default: cout << "Opcion no valida." << endl;
        }
    } while (opcion != 0);

    return 0;
}
