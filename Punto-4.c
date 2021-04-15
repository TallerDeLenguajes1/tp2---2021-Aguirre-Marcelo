#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    int velocidad;
    int anio;
    int cantidad;
    char nombre[10];
} compu;

void mostrar(compu *);
void mostrarArreglo(compu *, int);
void cargar(compu *);
void cargarArreglo(compu *, int);
void pcMasVieja(compu *, int);
void pcMasVelos(compu *, int);

int main()
{
    srand(time(NULL));
    compu *cantidadPc;
    int cantidad;
    printf("Ingrese la cantidad de pc a guardar: ");
    scanf("%d", &cantidad);

    cantidadPc = (compu *)malloc(sizeof(compu) * cantidad);
    cargarArreglo(cantidadPc, cantidad);
    mostrarArreglo(cantidadPc, cantidad);
    pcMasVieja(cantidadPc, cantidad);
    pcMasVelos(cantidadPc, cantidad);
    
    
    free(cantidadPc);

    return 0;
}

void cargar(compu *cantidadPc)
{
    cantidadPc->velocidad = rand() % 3 + 1;
    cantidadPc->anio = rand() % 18 + 2000;
    cantidadPc->cantidad = rand() % 4 + 1;

    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};

    int ran = rand() % 6;

    for (int i = 0; i < 10; i++)
    {
        cantidadPc->nombre[i] = tipos[ran][i];
    }
}

void cargarArreglo(compu *puntero, int cantidad)
{

    for (int i = 0; i < cantidad; i++)
    {
        cargar(puntero);
        puntero++;
    }
}

void mostrar(compu *puntero)
{
    printf("------------------------------------\n");
    printf("Velocidad: %d Gherz\n", puntero->velocidad);
    printf("Anio: %d\n", puntero->anio);
    printf("Cantidad de nucleos: %d\n", puntero->cantidad);

    printf("Nombre: %s\n", puntero->nombre);
}

void mostrarArreglo(compu *puntero, int cantidad)
{

    for (int i = 0; i < cantidad; i++)
    {
        mostrar(puntero);
        puntero++;
    }
}

void pcMasVieja(compu *puntero, int cantidad)
{

    int aux = puntero->anio;
    printf("\n--------------------");
    for (int i = 0; i < cantidad; i++)
    {
        if (puntero->anio < aux)
        {

            aux = puntero->anio;
        }
        puntero++;
    }
    printf("\nPc mas vieja: %d", aux);
}

void pcMasVelos(compu *puntero, int cantidad)
{

    int aux, aux2, aux3, i;
    char aux1[10];

    aux = puntero->velocidad;

    for ( i = 0; i < cantidad; i++)
    {
        if (aux < puntero->velocidad)
        {
            aux = puntero->velocidad;
            for ( i = 0; i < 10; i++)
            {
                aux1[i] = puntero->nombre[i];
            }
            aux2 = puntero->cantidad;
            aux3 = puntero->anio;
        }
        puntero++;
    }
    printf("\n--------------------");
    printf("\nPc mas veloz:\n");
    printf("Nombre: %s\n", aux1);
    printf("Velocidad: %d Ghez <-----\n", aux);
    printf("Anio: %d\n", aux3);
    printf("Cantidad de nucleos: %d\n", aux2);

    
}