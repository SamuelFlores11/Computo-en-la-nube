// pruebaOMP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Importamos las librerias
#include <iostream>
#include <omp.h>

//Definimos variables 
#define N 10
#define chunk 2
#define mostrar 5

void imprimeArreglo(float* d);

//Iniciamos programa principal
int main()
{
    //Imprimimos mensaje y declaramos variables
    std::cout << "Sumando Arreglos en Paralelo!\n";
    float a[N], b[N], c[N];
    int i;

    //Generamos los valores de los arreglos a y b
    for (i = 0; i < N; i++)
    {
        a[i] = i * 10;
        b[i] = (i + 3) * 3.7;
    }


    int pedazos = chunk;

    //generamos el procesamiento paralelo
    #pragma omp parallel for \
    shared(a, b, c, pedazos) private(i) \
    schedule(static, pedazos)

    //Realizamos la suma de arreglos
    for (i = 0; i < N; i++)
        c[i] = a[i] + b[i];

    //Imprimimos y mandamos a llamar funcion para mostrar los elementos de los arreglos
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo a: " << std::endl;
    imprimeArreglo(a);
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo b: " << std::endl;
    imprimeArreglo(b);
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo c: " << std::endl;
    imprimeArreglo(c);
}

//Funcion para mostrar los valores de cada elemento del arreglo
void imprimeArreglo(float* d)
{
    for (int x = 0; x < mostrar; x++)
        std::cout << d[x] << " - ";
    std::cout << std::endl;
}


/*
   std::cout << "Verificando la ejecución de las directivas OMP!\n";

   # ifdef _OPENMP
       std::cout << "OMP disponible y funcionando" << std::endl;
   # endif

*/

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
