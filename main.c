#include <stdio.h>
#include <stdlib.h>

#include "vectores.h"
#include "matrices.h"

/// @author Leandro Blandi

void procedimientoVectores();
void procedimientoMatrices();

int main() {
    // Separe el main en dos procedimientos para legibilidad
    procedimientoVectores();
    procedimientoMatrices();
    return 0;
}

void procedimientoVectores() {
    // Creamos y mostramos
    // un vector con tamaño 10 y numeros aleatorios entre 10-20
    int t = 10;
    int * v = crearVector(t);
    cargarVectorAleatorio(v, t, 10, 20);
    mostrarVector(v, t);

    // Mostramos pares, modulo, minimo y maximo del vector `v`
    printf("\n- Pares en el vector: %d", getCantidadPares(v, t));
    printf("\n- Modulo del vector: %.2f", calcularModulo(v, t));
    printf("\n- Minimo del vector: %d", buscarMinimo(v, t));
    printf("\n- Maximo del vector: %d\n", buscarMaximo(v, t));

    // Ordenamos y mostramos el vector `v`
    printf("\nOrdenando vector(%p):", &v);
    ordenarInsercion(v, t);
    //ordenarBurbujeo(v, t);
    //ordenarSeleccion(v, t);
    mostrarVector(v, t);

    // Creamos un segundo vector, con mismo tamaño y rango
    // de aleatorios
    int * v2 = crearVector(t);
    cargarVectorAleatorio(v2, t, 10, 20);
    mostrarVector(v2, t);

    // Sumamos los vectores y mostramos el resultado
    printf("\nSuma de vectores:");
    int * sumaVectores = sumarVectores(v, v2, t);
    mostrarVector(sumaVectores, t);

    // Mostramos el producto escalar de `v` y `v2`
    printf("\nProducto escalar de vectores: %d", multiplicarEscalar(v, v2, t));

    // Buscamos un numero dentro del vector `v`
    int numeroBusqueda = 11;
    printf("\nEl numero %d esta en la posicion %d", numeroBusqueda, busquedaSecuencial(v, t, numeroBusqueda));
    //printf("\nEl numero %d esta en la posicion %d", numeroBusqueda, busquedaBinaria(v, t, numeroBusqueda));

    liberarVector(v);
    liberarVector(v2);
    liberarVector(sumaVectores);
}

void procedimientoMatrices() {
    // Seteamos renglones y columnas
    int r = 3;
    int c = 3;

    // Cargamos y mostramos la matriz
    int ** matriz = crearMatriz(r, c);
    cargarMatrizAleatoria(matriz, r, c, 10, 40);
    mostrarMatriz(matriz, r, c);

    // Buscamos minimo
    int * datosMatriz = buscarMinimoMatriz(matriz, r, c);
    printf("\nMinimo matriz:");
    mostrarVector(datosMatriz, 2);
    liberarVector(datosMatriz);

    // Buscamos maximo reutilizando `datosMatriz`
    datosMatriz = buscarMaximoMatriz(matriz, r, c);
    printf("\nMaximo matriz:");
    mostrarVector(datosMatriz, 2);
    liberarVector(datosMatriz);

    // Promedio por renglones y columnas
    calcularPromedioRenglones(matriz, r, c);
    calcularPromedioColumnas(matriz, r, c);

    // Suma por renglones y columnas
    calcularSumaRenglones(matriz, r, c);
    calcularSumaColumnas(matriz, r, c);
    printf("\n\nPromedio total matriz: %.2f", calcularPromedioTotal(matriz, r, c));

    // Creamos una segunda matriz
    int ** matriz2 = crearMatriz(r, c);
    cargarMatrizAleatoria(matriz2, r, c, 1, 10);
    printf("\n\nSegunda matriz:");
    mostrarMatriz(matriz2, r, c);

    // Sumamos matriz + matriz2
    int ** suma = sumarMatrices(matriz, matriz2, r, c);
    printf("\n\nSuma de matrices:");
    mostrarMatriz(suma, r, c);

    // Multiplicamos matriz * matriz2
    int ** producto = multiplicarMatrices(matriz, matriz2, r, c);
    printf("\n\nProducto de matrices:");
    mostrarMatriz(producto, r, c);

    liberarMatriz(matriz, r);
    liberarMatriz(matriz2, r);
    liberarMatriz(suma, r);
    liberarMatriz(producto, r);
}
