#ifndef VECTORES_H_INCLUDED
#define VECTORES_H_INCLUDED

#include<stdbool.h>

/// @author Leandro Blandi

/// @brief Reserva memoria para un vector
/// @param t int El tamaño maximo del vector
int * crearVector(int t);

/// @brief Libera el segmento de memoria que ocupa v
/// @param v * int El vector a destruir
void liberarVector(int * v);

/// @brief Carga un vector con numeros aleatorios
/// @param v *int El vector
/// @param t int El tamaño del vector
/// @param vMin int El minimo aleatorio
/// @param vMax int El maximo aleatorio
void cargarVectorAleatorio(int * v, int t, int vMin, int vMax);

/// @brief Carga un vector con numeros ingresados por teclado
/// @param v *int El vector
/// @param t int El tamaño del vector
void cargarVectorDesdeTeclado(int * v, int t);

/// @brief Busca un elemento `a` mediante busqueda binaria en el vector y devuelve la posicion
/// @param x int El valor de la coordenada X
/// @param y int El valor de la coordenada Y
void cargarCoordenadasVector(int * v, int x, int y);

/// @brief Muestra el vector por pantalla
/// @param v *int El vector
/// @param t int El tamaño del vector
void mostrarVector(int * v, int t);

/// @brief Muestra el vector desde fin a inicio, es decir, invertido
/// @param v *int El vector
/// @param t int El tamaño del vector
void mostrarVectorInvertido(int * v, int t);

/// @brief Muestra una posicion del vector, utilizado internamente en los mostrarVector
/// @param v *int El vector
/// @param t int El tamaño del vector
/// @param i int La posicion a mostrar
void mostrarPosicion(int * v, int t, int i, bool invertido);

/// @brief Retorna la cantidad de numeros divisibles por 2
/// @param v *int El vector
/// @param t int El tamaño del vector
int getCantidadPares(int * v, int t);

/// @brief Calcula el modulo del vector, utilizando el T. de Pitagoras
/// @param v *int El vector
/// @param t int El tamaño del vector
float calcularModulo(int * v, int t);

/// @brief Retorna el numero minimo del vector
/// @param v *int El vector
/// @param t int El tamaño del vector
int buscarMinimo(int * v, int t);

/// @brief Retorna el numero maximo del vector
/// @param v *int El vector
/// @param t int El tamaño del vector
int buscarMaximo(int * v, int t);

/// @brief Ordena el vector mediante BubbleSort
/// @param v *int El vector
/// @param t int El tamaño del vector
void ordenarBurbujeo(int * v, int t);

/// @brief Ordena el vector mediante SelectionSort
/// @param v *int El vector
/// @param t int El tamaño del vector
void ordenarSeleccion(int * v, int t);

/// @brief Ordena el vector mediante InsertionSort
/// @param v *int El vector
/// @param t int El tamaño del vector
void ordenarInsercion(int * v, int t);

/// @brief Suma dos vectores posicion a posicion y retorna un nuevo vector con la suma
///        Se asume que ambos vectores tienen los mismos tamaños
/// @param v1 *int El vector 1
/// @param v2 *int El vector 2
/// @param t int El tamaño de los vectores
int * sumarVectores(int * v1, int * v2, int t);

/// @brief Multiplica dos vectores posicion a posicion y retorna un nuevo vector con la suma
///        Se asume que ambos vectores tienen los mismos tamaños
/// @param v1 *int El vector 1
/// @param v2 *int El vector 2
/// @param t int El tamaño de los vectores
int multiplicarEscalar(int * v1, int * v2, int t);

/// @brief Busca un elemento `a` mediante busqueda secuencial en el vector y devuelve la posicion
/// @param v *int El vector
/// @param t int El tamaño del vector
/// @param a int el elemento a buscar
int busquedaSecuencial(int * v, int t, int a);

/// @brief Busca un elemento `a` mediante busqueda binaria en el vector y devuelve la posicion
/// @param v *int El vector
/// @param t int El tamaño del vector
/// @param a int el elemento a buscar
int busquedaBinaria(int * v, int t, int a);

#endif // VECTORES_H_INCLUDED
