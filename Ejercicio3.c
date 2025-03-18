#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000 // Tamaño de la matriz (N x N)

// Medir tiempo de acceso a un vector varias veces
double recorrerVector(int *vec, size_t tamano) {
    clock_t inicio = clock();
    long long suma = 0;

    for (int rep = 0; rep < 10; rep++) { // Recorrer varias veces
        for (size_t i = 0; i < tamano; i++) {
            suma += vec[i];
        }
    }

    clock_t fin = clock();
    return (double)(fin - inicio) / CLOCKS_PER_SEC;
}

// Medir acceso a una matriz almacenada en un vector (acceso por filas)
double accesoFila(int *matriz) {
    clock_t inicio = clock();
    long long suma = 0;

    for (int i = 0; i < N; i++) {      
        for (int j = 0; j < N; j++) {  
            suma += matriz[i * N + j]; // Acceso por filas
        }
    }

    clock_t fin = clock();
    return (double)(fin - inicio) / CLOCKS_PER_SEC;
}

// Medir acceso a la matriz por columnas
double accesoColumna(int *matriz) {
    clock_t inicio = clock();
    long long suma = 0;

    for (int j = 0; j < N; j++) {      
        for (int i = 0; i < N; i++) {  
            suma += matriz[i * N + j]; // Acceso por columnas
        }
    }

    clock_t fin = clock();
    return (double)(fin - inicio) / CLOCKS_PER_SEC;
}

int main() {
    int *vector = (int *)malloc(N * N * sizeof(int));
    int *matriz = (int *)malloc(N * N * sizeof(int));

    if (vector == NULL || matriz == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    // Inicializar vector y matriz
    for (size_t i = 0; i < N * N; i++) {
        vector[i] = i + 1;
        matriz[i] = i + 1;
    }

    // Medir tiempos
    double tiempoVector = recorrerVector(vector, N * N);
    double tiempoFila = accesoFila(matriz);
    double tiempoColumna = accesoColumna(matriz);

    // Mostrar resultados
    printf("Recorrido de vector varias veces: %f segundos\n", tiempoVector);
    printf("Acceso por filas (mejor localidad): %f segundos\n", tiempoFila);
    printf("Acceso por columnas (peor localidad): %f segundos\n", tiempoColumna);

    // Liberar memoria
    free(vector);
    free(matriz);

    return 0;
}
