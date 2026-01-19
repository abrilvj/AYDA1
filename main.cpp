#include <iostream>
#include <vector>
#include <algorithm>
#include "ejercicios.h"

using namespace std;

// EJ 1: mergesort y quicksort
void Merge (vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> leftArr(n1);
    vector<int> rightArr(n2);

    // cargar arrays
    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left+i];
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = arr[mid+1+j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while ((i < n1) && (j<n2)) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // copiar elementos restantes si hubiera
    while (i<n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j<n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
 }


void MergeSort (vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = (left + right)/2;

        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);

        Merge(arr,left,mid,right);
    }
}

int partitionate (vector<int>& arr, int low, int high)
 {
     int pivot = arr[high]; // ultimo elemento

     int i = low;
     for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
     }

     // intercambiar pivot con ultimo elemento
     swap(arr[i], arr[high]);
     return i; // indice del pivot
 }

void Quicksort (vector<int>& arr, int low, int high) {
    if (low >= high) {
        return;
    }

    int pivot = partitionate(arr, low, high);

    Quicksort(arr, low, pivot - 1); // el elemento pivot se excluye porque ya queda ordenado
    Quicksort(arr, pivot + 1, high);
}

void mostrarArreglo (vector<int> arreglo) {
    for (int i=0; i < arreglo.size(); i++){
        cout << arreglo[i] << " ";
    }
}

int main()
{
    vector<int> arreglo = {-1, 0, 2, 5, -7, 9};

    //MergeSort(arreglo, 0, arreglo.size()-1);

    //Quicksort(arreglo, 0, arreglo.size()-1);


    int opcion;

    do {
        cout << "\n TRABAJO PRACTICO 1 " << endl;
        cout << " nro de ejercicio" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: Quicksort(arreglo, 0, arreglo.size()-1);
                    mostrarArreglo(arreglo);
                    break;
            case 2: cout << ejercicio2(arreglo, 0 , arreglo.size() - 1) << endl;
                    break;
            case 3: { int minimo = 0;
                    int maximo = 0;
                    ejercicio3(arreglo,0, arreglo.size()-1, minimo, maximo);
                    cout << "minimo: " << minimo << " maximo: " << maximo << endl;
                    break; }
            case 4: cout << ejercicio4(arreglo, 0, arreglo.size()-1) << endl; break;
            case 0: cout << "Saliendo..." << endl; break;
            default: cout << "Opcion no valida." << endl;
        }
    } while (opcion != 0);

    return 0;
}
