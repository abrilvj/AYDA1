#ifndef EJERCICIOS_H_INCLUDED
#define EJERCICIOS_H_INCLUDED
#include <vector>
struct Tarea {
    int id; // para identificar que tarea es
    int ganancia;
    int limite;
};
struct Proceso {
    int id;
    int tiempo;
};
struct Actividad {
    int id;
    int inicio;
    int fin;
};
void ejercicio1(int capacidad, std::vector<int>& peso, std::vector<int>& valor);

void ejercicio2(std::vector<Tarea>& tareas);

void ejercicio3(std::vector<Proceso>& procesos);

void ejercicio4(std::vector<Actividad>& actividades);

#endif // EJERCICIOS_H_INCLUDED
