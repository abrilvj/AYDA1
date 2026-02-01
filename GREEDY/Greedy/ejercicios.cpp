#include <iostream>
#include <vector>
#include <algorithm> // Para std::sort
#include "ejercicios.h"

using namespace std;

struct Objeto {
    int peso;
    int valor;
    double ratio;
};

void ejercicio1(int capacidad, std::vector<int>& peso, std::vector<int>& valor) {
    int n = peso.size();
    vector<Objeto> objetos(n);

    for (int i = 0; i < n; i++) {
        objetos[i].peso = peso[i];
        objetos[i].valor = valor[i];
        // Calculamos el valor relativo (usamos double para precisión)
        objetos[i].ratio = (double)valor[i] / peso[i];
    }

    sort(objetos.begin(), objetos.end(), [](const Objeto& a, const Objeto& b) {
        return a.ratio > b.ratio; //orden desc
    });

    double valorTotal = 0;
    int pesoAct = 0;

    for (Objeto& obj : objetos) {
        if (pesoAct + obj.peso <= capacidad) {
            pesoAct = pesoAct + obj.peso ;
            valorTotal = valorTotal + obj.valor;
        } else {
            double fraccion = (double) (capacidad - pesoAct) / capacidad;
            valorTotal = valorTotal + (fraccion * obj.valor);
            pesoAct = capacidad;
            break;
        }
    }
    cout << "Valor total en la mochila: " << valorTotal << endl;
}

void ejercicio2 (vector<Tarea>& tareas){
    vector<int> resultado(5); // tamanio debe ser el max de limite
    // ordenar tareas
    sort(tareas.begin(), tareas.end(), [](const Tarea& a, const Tarea& b) {
        return a.ganancia > b.ganancia; //orden desc
    });

    for (Tarea t : tareas) {
         for (int j = t.limite; j > 0; j--){ // a partir de tiempo 1 pq 0 no se toma
            if (resultado[j] == 0) // se supone q se inicializa en 0 el vector
            {
                resultado[j] = t.id;  // agregar a la secuencia el id d tarea
                break;
            }
         }
    }

    cout << "Secuencia optima: ";
    for (int i = 1; i < resultado.size(); i++) {
        if (resultado[i] != 0) {
            cout << resultado[i] << " ";
        }
    }
    cout << endl;
}



void ejercicio3(vector<Proceso>& procesos) {
    vector<int> resultado(procesos.size());

    sort(procesos.begin(), procesos.end(), [](const Proceso& a, const Proceso& b) {
        return a.tiempo < b.tiempo; //orden asc
    }); // orden ascendente

    for (int i = 0; i < procesos.size(); i++){
        resultado[i] = procesos[i].id;
    }

    cout << "Secuencia optima: ";
    for (int i = 0; i < resultado.size(); i++) {
        if (resultado[i] != 0) {
            cout << resultado[i] << " ";
        }
    }
    cout << endl;
}

void ejercicio4(vector<Actividad>& actividades) {
    vector<Actividad> resultado;

    // ordenar segun las que finalizan antes
    sort(actividades.begin(), actividades.end(), [](const Actividad& a, const Actividad& b) {
        return a.fin < b.fin; //orden asc
    }); // orden ascendente

    // 2. La primera actividad siempre se elige
    resultado.push_back(actividades[0]);
    int finUltima = actividades[0].fin; // Guardamos cuándo termina la última

    for (int i=1; i<actividades.size();i++) {
        if (actividades[i].inicio >= finUltima) {
            resultado.push_back(actividades[i]);
            finUltima = actividades[i].fin; // Actualizamos el tiempo de "sala ocupada"
        }
    }

    cout << "Secuencia optima: ";
    for (int i = 0; i < resultado.size(); i++) {
        cout << resultado[i].id << " ";
    }
    cout << endl;
}
