#include <iostream>
#include <vector>
#include "ejercicios.h"

using namespace std;

/* Sea T un arreglo ordenado de n enteros diferentes, alguno de los cuales pueden ser negativos.
Escriba un algoritmo en C++ que encuentre el índice i tal que 0 ≤ i < n y T[i] = i, siempre y cuando
exista tal índice. La complejidad temporal de la solución propuesta debe pertenecer a O(log n) */
int ejercicio2 (vector<int>& arr, int low, int high){
    if (low > high) {
        return -1;
    }
    int mid = low + (high - low) / 2;

    // caso base: lo encontramos
    if (arr[mid] == mid){
        return mid;
    }

    // dividir y conquistar
    if (arr[mid] > mid) { // valor mas grande que el indice,buscar en la 1era mitad
        return ejercicio2(arr, low, mid - 1);
    } else {
        return ejercicio2(arr, mid + 1, high);
    }
}

/*  Escriba un algoritmo en C++ que dado un arreglo de enteros encuentre los enteros máximo y
mínimo: */
void ejercicio3 (vector<int>& arr, int izq, int der, int& minimo, int& maximo) {
    int mid;

    // Caso base 1: El arreglo tiene un solo elemento
    if (izq == der) {
        maximo = arr[izq];
        minimo = arr[izq];
        return;
    }

    // Caso base 2: El arreglo tiene dos elementos
    if (der == izq + 1) {
        if (arr[izq] > arr[der]) {
            maximo = arr[izq];
            minimo = arr[der];
        } else {
            maximo = arr[der];
            minimo = arr[izq];
        }
        return;
    }

    // Divide: Encontrar el punto medio y dividir el problema
    mid = izq + (der - izq) / 2;

    int izqMin, izqMax;
    int derMin, derMax;
    ejercicio3(arr, izq, mid, izqMin, izqMax);
    ejercicio3(arr, mid + 1, der, derMin, derMax);

    // Conquista/Combina: Comparar los resultados de ambas mitades
    minimo = min(izqMin, derMin);
    maximo = max(izqMax, derMax);

    return;
}

int crossSum (vector<int>& arr, int izq, int mid, int der) {
    int acumIzq = INT_MIN;
    int acumDer = INT_MIN;
    int suma = 0;

    for (int i = mid; i >= izq; i--){
        suma = suma + arr[i];
        if (suma > acumIzq) {
            acumIzq = suma;
        }
    }
    suma = 0;
    for (int i = mid + 1; i <= der; i++){
        suma = suma + arr[i];
        if (suma > acumDer) {
            acumDer = suma;
        }
    }

    return (acumIzq + acumDer);
}

// subarreglo de suma maxima
int ejercicio4 (vector<int>& arr, int izq, int der) {
    // caso invalido
    if (izq > der) {
        return INT_MIN;
    }

    if (izq == der){
        return arr[izq];
    }

    int mid = izq + (der - izq)/2;

    int sumaIzq = ejercicio4(arr, izq, mid);
    int sumaDer = ejercicio4(arr, mid + 1, der);
    int sumaCruz = crossSum(arr, izq, mid, der);

    return max(sumaIzq, max(sumaDer, sumaCruz));
}
