#ifndef MATRICES_H_INCLUDED
#define MATRICES_H_INCLUDED

/// @author Leandro Blandi

/// @brief Reserva memoria para una matriz
/// @param r int Cantidad de renglones
/// @param c int Cantidad de columnas
int ** crearMatriz(int r, int c);

/// @brief Libera el segmento de memoria ocupado por la matriz
/// @param r int Cantidad de renglones
void liberarMatriz(int ** m, int r);

/// @brief Muestra por pantalla los datos de la matriz
/// @param r int Cantidad de renglones
/// @param c int Cantidad de columnas
void mostrarMatriz(int ** m, int r, int c);

/// @brief Carga una matriz con numeros aleatorios
/// @param m **int La matriz
/// @param r int Cantidad de renglones
/// @param vMin int Valor aleatorio minimo
/// @param vMax int Valor aleatorio maximo
/// @param c int Cantidad de columnas
void cargarMatrizAleatoria(int ** m, int r, int c, int vMin, int vMax);

/// @brief Carga una matriz con numeros ingresados por teclado
/// @param m **int La matriz
/// @param r int Cantidad de renglones
/// @param c int Cantidad de columnas
void cargarMatrizPorTeclado(int ** m, int r, int c);

/// @brief Busca el minimo dentro de una matriz
/// @param m **int La matriz
/// @param r int Cantidad de renglones
/// @param c int Cantidad de columnas
int * buscarMinimoMatriz(int ** m, int r, int c);

/// @brief Busca el maximo dentro de una matriz
/// @param m **int La matriz
/// @param r int Cantidad de renglones
/// @param c int Cantidad de columnas
int * buscarMaximoMatriz(int ** m, int r, int c);

/// @brief Calcula el promedio renglon a renglon y lo imprime por pantalla
/// @param m **int La matriz
/// @param r int Cantidad de renglones
/// @param c int Cantidad de columnas
void calcularPromedioRenglones(int ** m, int r, int c);

/// @brief Calcula el promedio columna a columna y lo imprime por pantalla
/// @param m **int La matriz
/// @param r int Cantidad de renglones
/// @param c int Cantidad de columnas
void calcularPromedioColumnas(int ** m, int r, int c);

/// @brief Calcula la suma columna a columna y lo imprime por pantalla
/// @param m **int La matriz
/// @param r int Cantidad de renglones
/// @param c int Cantidad de columnas
void calcularSumaRenglones(int ** m, int r, int c);

/// @brief Calcula la suma columna a columna
/// @param m **int La matriz
/// @param r int Cantidad de renglones
/// @param c int Cantidad de columnas
void calcularSumaColumnas(int ** m, int r, int c);

/// @brief Suma todos los elementos de la matriz y lo divide por la cantidad total de elementos
/// @param m **int La matriz
/// @param r int Cantidad de renglones
/// @param c int Cantidad de columnas
float calcularPromedioTotal(int ** m, int r, int c);

/// @brief Suma dos matrices de igual tamaño, y lo inserta en una
///        nueva matriz
/// @param m **int La matriz
/// @param r int Cantidad de renglones
/// @param c int Cantidad de columnas
int ** sumarMatrices(int ** m1, int ** m2, int r, int c);

/// @brief Multiplica dos matrices de igual tamaño y lo inserta en una
///        nueva matriz
/// @param m **int La matriz
/// @param r int Cantidad de renglones
/// @param c int Cantidad de columnas
int ** multiplicarMatrices(int ** m1, int ** m2, int r, int c);

#endif // MATRICES_H_INCLUDED
