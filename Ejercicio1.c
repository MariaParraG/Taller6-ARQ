#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función para sumar un vector y medir el tiempo
void medirTiempo(size_t tamano) {
    int *vec = (int *)malloc(tamano * sizeof(int));
    if (vec == NULL) {
        printf("Error al asignar memoria.\n");
        return;
    }

    // Inicializar el vector con valores consecutivos
    for (size_t i = 0; i < tamano; i++) {
        vec[i] = i + 1;
    }

    // Medir tiempo antes de la suma
    clock_t inicio = clock();

    // Sumar los elementos del vector
    long long suma = 0;
    for (size_t i = 0; i < tamano; i++) {
        suma += vec[i];
    }

    // Medir tiempo después de la suma
    clock_t fin = clock();
    double tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;

    // Mostrar resultado
    printf("Tamaño: %lu - Tiempo: %f segundos\n", tamano, tiempo);

    free(vec);
}

int main() {
    size_t tamanos[] = {10000, 100000, 1000000, 10000000};

    for (int i = 0; i < 4; i++) {
        medirTiempo(tamanos[i]);
    }

    return 0;
}
