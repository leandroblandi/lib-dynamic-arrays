#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#include "vectores.h"
#include "matrices.h"

/// @brief Reserva memoria para una matriz
/// @param r int Cantidad de renglones
/// @param c int Cantidad de columnas
int ** crearMatriz(int r, int c) {
    int ** matriz = (int **) malloc(r * sizeof(int *));

    if (matriz == NULL) {
        return NULL;
    }

    for (int i = 0; i < r; i++) {
        matriz[i] = (int *) malloc(c * sizeof(int));
    }

    return matriz;
}

/// @brief Libera el segmento de memoria ocupado por la matriz
/// @param r int Cantidad de renglones
void liberarMatriz(int ** m, int r) {
    if (m == NULL) {
        return;
    }
    for (int i = 0; i < r; i++) {
        free(m[i]);
    }
    free(m);
}

/// @brief Muestra por pantalla los datos de la matriz
/// @param r int Cantidad de renglones
/// @param c int Cantidad de columnas
void mostrarMatriz(int ** m, int r, int c) {
    if (m == NULL || r <= 0 || c <= 0) {
        return;
    }
    printf("\n=== Matriz ===\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf(" %d ", m[i][j]);
        }
        printf("\n");
    }
}

/// @brief Carga una matriz con numeros aleatorios
/// @param m **int La matriz
/// @param r int Cantidad de renglones
/// @param vMin int Valor aleatorio minimo
/// @param vMax int Valor aleatorio maximo
/// @param c int Cantidad de columnas
void cargarMatrizAleatoria(int ** m, int r, int c, int vMin, int vMax) {
    if (m == NULL || r <= 0 || c <= 0) {
        return;
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            m[i][j] = vMin + rand() % (vMax - vMin + 1);
        }
    }
}

/// @brief Carga una matriz con numeros ingresados por teclado
/// @param m **int La matriz
/// @param r int Cantidad de renglones
/// @param c int Cantidad de columnas
void cargarMatrizPorTeclado(int ** m, int r, int c) {
    if (m == NULL || r <= 0 || c <= 0) {
        return;
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("\npos(%d;%d) > ", i, j);
            scanf("%d", &m[i][j]);
        }
    }
}

/// @brief Busca el minimo dentro de una matriz
/// @param m **int La matriz
/// @param r int Cantidad de renglones
/// @param c int Cantidad de columnas
int * buscarMinimoMatriz(int ** m, int r, int c) {
    if (m == NULL || r <= 0 || c <= 0) {
        return;
    }
    int x = 0;
    int y = 0;
    int minimo = m[x][y];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (m[i][j] < minimo) {
                minimo = m[i][j];
                x = i;
                y = j;
            }
        }
    }
    int * coordenadasMinimo = crearVector(2);
    cargarCoordenadasVector(coordenadasMinimo, x, y);
    return coordenadasMinimo;
}

/// @brief Busca el maximo dentro de una matriz
/// @param m **int La matriz
/// @param r int Cantidad de renglones
/// @param c int Cantidad de columnas
int * buscarMaximoMatriz(int ** m, int r, int c) {
    if (m == NULL || r <= 0 || c <= 0) {
        return;
    }
    int x = 0;
    int y = 0;
    int maximo = m[x][y];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (m[i][j] > maximo) {
                maximo = m[i][j];
                x = i;
                y = j;
            }
        }
    }
    int * coordenadasMaximo = crearVector(2);
    cargarCoordenadasVector(coordenadasMaximo, x, y);
    return coordenadasMaximo;
}

/// @brief Calcula el promedio renglon a renglon y lo imprime por pantalla
/// @param m **int La matriz
/// @param r int Cantidad de renglones
/// @param c int Cantidad de columnas
void calcularPromedioRenglones(int ** m, int r, int c) {
    if (m == NULL || r <= 0 || c <= 0) {
        return;
    }
    int cantidadElementos = 0;
    int suma = 0;
    float promedio = 0;
    printf("\n\nCalculo de promedio de matriz(%p)", (void **) m);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            suma += m[i][j];
            cantidadElementos++;
        }
        if (cantidadElementos == 0) {
            continue;
        }
        promedio = (float) suma / (float) cantidadElementos;
        printf("\n- Promedio renglon %d: %.2f", i + 1, promedio);
        suma = 0;
        cantidadElementos = 0;
    }
}

/// @brief Calcula el promedio columna a columna y lo imprime por pantalla
/// @param m **int La matriz
/// @param r int Cantidad de renglones
/// @param c int Cantidad de columnas
void calcularPromedioColumnas(int ** m, int r, int c) {
    if (m == NULL || r <= 0 || c <= 0) {
        return;
    }
    int cantidadElementos = 0;
    int suma = 0;
    float promedio = 0;
    printf("\n\nCalculo de promedio de matriz(%p)", (void **) m);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            suma += m[j][i];
            cantidadElementos++;
        }
        if (cantidadElementos == 0) {
            continue;
        }
        promedio = (float) suma / (float) cantidadElementos;
        printf("\n- Promedio columna %d: %.2f", i + 1, promedio);
        suma = 0;
        cantidadElementos = 0;
    }
}

/// @brief Calcula la suma columna a columna y lo imprime por pantalla
/// @param m **int La matriz
/// @param r int Cantidad de renglones
/// @param c int Cantidad de columnas
void calcularSumaRenglones(int ** m, int r, int c) {
    if (m == NULL || r <= 0 || c <= 0) {
        return;
    }
    int suma = 0;
    printf("\n\nSuma de renglones matriz(%p)", (void **) m);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            suma += m[i][j];
        }
        printf("\n- Suma de renglon %d: %d", i + 1, suma);
        suma = 0;
    }
}

/// @brief Calcula la suma columna a columna
/// @param m **int La matriz
/// @param r int Cantidad de renglones
/// @param c int Cantidad de columnas
void calcularSumaColumnas(int ** m, int r, int c) {
    if (m == NULL || r <= 0 || c <= 0) {
        return;
    }
    int suma = 0;
    printf("\n\nSuma de columnas matriz(%p)", (void **) m);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            suma += m[j][i];
        }
        printf("\n- Suma de columna %d: %d", i + 1, suma);
        suma = 0;
    }
}

/// @brief Suma todos los elementos de la matriz y lo divide por la cantidad total de elementos
/// @param m **int La matriz
/// @param r int Cantidad de renglones
/// @param c int Cantidad de columnas
float calcularPromedioTotal(int ** m, int r, int c) {
    if (m == NULL || r <= 0 || c <= 0) {
        return;
    }
    int cantidadElementos = 0;
    int suma = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            suma += m[j][i];
            cantidadElementos++;
        }
    }
    if (cantidadElementos == 0) {
        return 0;
    }
    return (float) suma / (float) cantidadElementos;
}

/// @brief Suma dos matrices de igual tamaño, y lo inserta en una
///        nueva matriz
/// @param m **int La matriz
/// @param r int Cantidad de renglones
/// @param c int Cantidad de columnas
int ** sumarMatrices(int ** m1, int ** m2, int r, int c) {
    if (m1 == NULL || m2 == NULL || r <= 0 || c <= 0) {
        return NULL;
    }
    // Asumimos que ambas matrices tienen igual rengs y cols
    int ** suma = crearMatriz(r, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            suma[i][j] = m1[i][j] + m2[i][j];
        }
    }
    return suma;
}

/// @brief Multiplica dos matrices de igual tamaño y lo inserta en una
///        nueva matriz
/// @param m **int La matriz
/// @param r int Cantidad de renglones
/// @param c int Cantidad de columnas
int ** multiplicarMatrices(int ** m1, int ** m2, int r, int c) {
    if (m1 == NULL || m2 == NULL || r <= 0 || c <= 0) {
        return NULL;
    }
    // Asumimos que ambas matrices tienen igual rengs y cols
    int ** producto = crearMatriz(r, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            producto[i][j] = m1[i][j] * m2[i][j];
        }
    }
    return producto;
}
