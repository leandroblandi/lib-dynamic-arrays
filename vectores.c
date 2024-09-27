#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#include "vectores.h"

/// @brief Reserva memoria para un vector
/// @param t int El tamaño maximo del vector
int * crearVector(int t) {
    return (int *) malloc(t * sizeof(int));
}

/// @brief Libera el segmento de memoria que ocupa v
/// @param v * int El vector a destruir
void liberarVector(int * v) {
    if (v == NULL) {
        return;
    }

    free(v);
}

/// @brief Carga un vector con numeros aleatorios
/// @param v *int El vector
/// @param t int El tamaño del vector
/// @param vMin int El minimo aleatorio
/// @param vMax int El maximo aleatorio
void cargarVectorAleatorio(int * v, int t, int vMin, int vMax) {
    if (v == NULL || t <= 0) {
        return;
    }
    srand(time(NULL));
    for (int i = 0; i < t; i++) {
        v[i] = vMin + rand() % (vMax - vMin + 1);
    }
}

/// @brief Carga un vector con numeros ingresados por teclado
/// @param v *int El vector
/// @param t int El tamaño del vector
void cargarVectorDesdeTeclado(int * v, int t) {
    if (v == NULL || t <= 0) {
        return;
    }
    printf("\nCargar vector desde teclado:");
    for (int i = 0; i < t; i++) {
        printf("\n(pos: %d) > ", i);
        scanf("%d", &v[i]);
    }
}

/// @brief Busca un elemento `a` mediante busqueda binaria en el vector y devuelve la posicion
/// @param x int El valor de la coordenada X
/// @param y int El valor de la coordenada Y
void cargarCoordenadasVector(int * v, int x, int y) {
    if ((v == NULL) || (x < 0 || y < 0)) {
        return;
    }

    // Asumimos que el largo del vector es de 2 posiciones
    v[0] = x;
    v[1] = y;
}

/// @brief Muestra el vector por pantalla
/// @param v *int El vector
/// @param t int El tamaño del vector
void mostrarVector(int * v, int t) {
    if (v == NULL || t <= 0) {
        return;
    }
    printf("\n(%p) = {", (void*) v);
    for (int i = 0; i < t; i++) {
        mostrarPosicion(v, t, i, false);
    }
    printf("}\n");
}

/// @brief Muestra el vector desde fin a inicio, es decir, invertido
/// @param v *int El vector
/// @param t int El tamaño del vector
void mostrarVectorInvertido(int * v, int t) {
    if (v == NULL || t <= 0) {
        return;
    }
    printf("\n(%p) = {", &v);
    for (int i = t - 1; i >= 0; i--) {
        mostrarPosicion(v, t, i, true);
    }
    printf("}\n");
}

/// @brief Muestra una posicion del vector, utilizado internamente en los mostrarVector
/// @param v *int El vector
/// @param t int El tamaño del vector
/// @param i int La posicion a mostrar
void mostrarPosicion(int * v, int t, int i, bool invertido) {
    if ((v == NULL) ||(i < 0) || (i > t)){
        return;
    }

    if (invertido) {
        if (i == 0) {
            printf("%d ", v[i]);
        } else {
            printf(" %d, ", v[i]);
        }
    } else {
        if (i == t - 1) {
            printf("%d ", v[i]);
        } else {
            printf(" %d, ", v[i]);
        }
    }
}

/// @brief Retorna la cantidad de numeros divisibles por 2
/// @param v *int El vector
/// @param t int El tamaño del vector
int getCantidadPares(int * v, int t) {
    if (v == NULL || t <= 0) {
        return;
    }
    int pares = 0;

    for (int i = 0; i < t; i++) {
        if (v[i] % 2 == 0) {
            pares++;
        }
    }

    return pares;
}

/// @brief Calcula el modulo del vector, utilizando el T. de Pitagoras
/// @param v *int El vector
/// @param t int El tamaño del vector
float calcularModulo(int * v, int t) {
    if (v == NULL || t <= 0) {
        return;
    }
    float sumaCuadrados = 0;

    for (int i = 0; i < t; i++) {
        sumaCuadrados += v[i] * v[i];
    }

    return sqrt(sumaCuadrados);
}

/// @brief Retorna el numero minimo del vector
/// @param v *int El vector
/// @param t int El tamaño del vector
int buscarMinimo(int * v, int t) {
    if (v == NULL || t <= 0) {
        return;
    }
    int min;
    for (int i = 0; i < t; i++) {
        if (i == 0) {
            min = v[i];
        }
        else if (v[i] < min) {
            min = v[i];
        }
    }
    return min;
}

/// @brief Retorna el numero maximo del vector
/// @param v *int El vector
/// @param t int El tamaño del vector
int buscarMaximo(int * v, int t) {
    if (v == NULL || t <= 0) {
        return;
    }
    int max;
    for (int i = 0; i < t; i++) {
        if (i == 0) {
            max = v[i];
        }
        else if (v[i] > max) {
            max = v[i];
        }
    }
    return max;
}

/// @brief Ordena el vector mediante BubbleSort
/// @param v *int El vector
/// @param t int El tamaño del vector
void ordenarBurbujeo(int * v, int t) {
    if (v == NULL || t <= 0) {
        return;
    }
    int auxiliar;
    for (int i = 0; i < t; i++) {
       for (int j = 0; j < (t - 1); j++) {
            if (v[j] > v[j + 1]) {
                auxiliar = v[j];
                v[j] = v[j + 1];
                v[j + 1] = auxiliar;
            }
        }
    }
}

/// @brief Ordena el vector mediante SelectionSort
/// @param v *int El vector
/// @param t int El tamaño del vector
void ordenarSeleccion(int * v, int t) {
    if (v == NULL || t <= 0) {
        return;
    }
    int posMinimo, auxiliar;

    for (int i = 0; i < t; i++) {
        posMinimo = i;

        for (int j = i + 1; j < t; j++) {
            if (v[j] < v[posMinimo]) {
                posMinimo = j;
            }
        }

        if (posMinimo != i) {
            auxiliar = v[i];
            v[i] = v[posMinimo];
            v[posMinimo] = auxiliar;
        }
    }
}

/// @brief Ordena el vector mediante InsertionSort
/// @param v *int El vector
/// @param t int El tamaño del vector
void ordenarInsercion(int * v, int t) {
    if (v == NULL || t <= 0) {
        return;
    }
    int clave, j;
    for (int i = 1; i < t; i++) {
        clave = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > clave) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = clave;
    }
}

/// @brief Suma dos vectores posicion a posicion y retorna un nuevo vector con la suma
///        Se asume que ambos vectores tienen los mismos tamaños
/// @param v1 *int El vector 1
/// @param v2 *int El vector 2
/// @param t int El tamaño de los vectores
int * sumarVectores(int * v1, int * v2, int t) {
    if (v1 == NULL || v2 == NULL || t <= 0) {
        return;
    }
    int * suma = crearVector(t);

    for (int i = 0; i < t; i++) {
        suma[i] = v1[i] + v2[i];
    }

    return suma;
}

/// @brief Multiplica dos vectores posicion a posicion y retorna un nuevo vector con la suma
///        Se asume que ambos vectores tienen los mismos tamaños
/// @param v1 *int El vector 1
/// @param v2 *int El vector 2
/// @param t int El tamaño de los vectores
int multiplicarEscalar(int * v1, int * v2, int t) {
    if (v1 == NULL || v2 == NULL || t <= 0) {
        return;
    }
    int multiplicacion = 0;
    for (int i = 0; i < t; i++) {
        multiplicacion += v1[i] * v2[i];
    }
    return multiplicacion;
}

/// @brief Busca un elemento `a` mediante busqueda secuencial en el vector y devuelve la posicion
/// @param v *int El vector
/// @param t int El tamaño del vector
/// @param a int el elemento a buscar
int busquedaSecuencial(int * v, int t, int a) {
    if (v == null || t <= 0) {
        return;
    }
    int pos = -1;
    int i = 0;
    while ((i < t) && (pos == -1)) {
        if (v[i] == a) {
            pos = i;
        }
        i++;
    }
    return pos;
}

/// @brief Busca un elemento `a` mediante busqueda binaria en el vector y devuelve la posicion
/// @param v *int El vector
/// @param t int El tamaño del vector
/// @param a int el elemento a buscar
int busquedaBinaria(int * v, int t, int a) {
    if (v == null || t <= 0) {
        return;
    }
    int izquierda = 0;
    int derecha = t - 1;
    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;
        if (v[medio] == a) {
            return medio;
        }
        if (v[medio] < a) {
            izquierda = medio + 1;
        }
        else {
            derecha = medio - 1;
        }
    }
    return -1;
}
