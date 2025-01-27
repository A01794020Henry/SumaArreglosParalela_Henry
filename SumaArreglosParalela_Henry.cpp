// SumaArreglosParalela_Henry.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>  // Librería estándar para entrada y salida (imprimir en consola)
#include <omp.h>     // Librería para manejo de procesamiento paralelo con OpenMP
#include <cstdlib>   // Librería para generar números aleatorios (rand)
#include <ctime>     // Librería para inicializar la semilla de números aleatorios (time)

// Definimos el tamaño del arreglo como una constante
const int TAM = 1000; // Los arreglos tendrán 1000 elementos

int main() {
    // Inicializamos la semilla para generar números aleatorios basándonos en el tiempo actual
    std::srand(std::time(0));

    // Declaramos tres arreglos de tamaño TAM:
    // A y B para almacenar los valores de entrada
    // R para almacenar el resultado de la suma
    int A[TAM], B[TAM], R[TAM];

    // *** Llenado de los arreglos con valores aleatorios ***
    // La directiva #pragma omp parallel for divide el trabajo de este bucle for entre múltiples hilos
    // Cada hilo llena una parte del arreglo A y B de forma simultánea
#pragma omp parallel for
    for (int i = 0; i < TAM; ++i) {
        A[i] = std::rand() % 100; // Genera un número aleatorio entre 0 y 99 para A[i]
        B[i] = std::rand() % 100; // Genera un número aleatorio entre 0 y 99 para B[i]
    }

    // *** Suma de los arreglos A y B en paralelo ***
    // Otro bucle paralelo para calcular la suma elemento por elemento
    // El resultado de cada suma se almacena en el arreglo R
#pragma omp parallel for
    for (int i = 0; i < TAM; ++i) {
        R[i] = A[i] + B[i]; // Suma de los elementos A[i] y B[i]
    }

    // *** Imprimir una parte de los arreglos para verificar los resultados ***
    // Mostramos los primeros 10 elementos de los arreglos A, B y R
    std::cout << "Primeros 10 elementos de los arreglos:\n";
    for (int i = 0; i < 10; ++i) {
        std::cout << "A[" << i << "] = " << A[i]  // Mostramos el valor de A[i]
            << ", B[" << i << "] = " << B[i] // Mostramos el valor de B[i]
            << ", R[" << i << "] = " << R[i] // Mostramos el valor resultante R[i]
            << '\n'; // Nueva línea después de cada elemento
    }

    // Mensaje final para confirmar que todo el proceso se ejecutó correctamente
    std::cout << "\nSuma de arreglos completada en paralelo.\n";

    return 0; // Fin del programa, devolvemos 0 indicando ejecución exitosa
}


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
