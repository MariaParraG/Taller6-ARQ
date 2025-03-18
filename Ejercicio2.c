#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definir tamaño del vector (gran tamaño)
#define TAMANO_VECTOR 10000000

// Función para medir acceso secuencial
double accesoSecuencial(int *vec, size_t tamano) {
    clock_t inicio = clock();
    long long suma = 0;

    for (size_t i = 0; i < tamano; i++) {
        suma += vec[i]; 
    }

    clock_t fin = clock();
    return (double)(fin - inicio) / CLOCKS_PER_SEC;
}

// Función para medir acceso aleatorio
double accesoAleatorio(int *vec, size_t tamano) {
    clock_t inicio = clock();
    long long suma = 0;

    for (size_t i = 0; i < tamano; i++) {
        size_t indice = rand() % tamano; // Índice aleatorio
        suma += vec[indice];
    }

    clock_t fin = clock();
    return (double)(fin - inicio) / CLOCKS_PER_SEC;
}

int main() {
    // Asignar memoria para el vector
    int *vec = (int *)malloc(TAMANO_VECTOR * sizeof(int));
    if (vec == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    // Inicializar el vector con valores consecutivos
    for (size_t i = 0; i < TAMANO_VECTOR; i++) {
        vec[i] = i + 1;
    }

    // Medir tiempos
    double tiempoSecuencial = accesoSecuencial(vec, TAMANO_VECTOR);
    double tiempoAleatorio = accesoAleatorio(vec, TAMANO_VECTOR);

    // Mostrar resultados
    printf("Acceso Secuencial: %f segundos\n", tiempoSecuencial);
    printf("Acceso Aleatorio: %f segundos\n", tiempoAleatorio);

    // Liberar memoria
    free(vec);

    return 0;
}
