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
void copiarPc(compu *, compu );

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

void pcMasVieja(compu *listado, int cantidad)
{

    compu miPcVieja;

    copiarPc(&miPcVieja, listado[0] );

    for (int i = 0; i < cantidad; i++)
    {
        if (miPcVieja.anio > listado[i].anio)
        {

            copiarPc(&miPcVieja, listado[i] );
        }      
    }
    
    printf("\n--------------------");
    printf("\nPc mas vieja:\n");
    printf("Nombre: %s\n", miPcVieja.nombre);
    printf("Velocidad: %d Ghez \n", miPcVieja.velocidad);
    printf("Anio: %d <-----\n", miPcVieja.anio);
    printf("Cantidad de nucleos: %d\n", miPcVieja.cantidad);
}

void pcMasVelos(compu *listado, int cantidad)
{

    compu miPc;

    copiarPc(&miPc, listado[0] );

    for (int i = 0; i < cantidad; i++)
    {
        if (miPc.velocidad < listado[i].velocidad)
        {

            copiarPc(&miPc, listado[i] );
        }      
    }
    
    printf("\n--------------------");
    printf("\nPc mas veloz:\n");
    printf("Nombre: %s\n", miPc.nombre);
    printf("Velocidad: %d Ghez <-----\n", miPc.velocidad);
    printf("Anio: %d\n", miPc.anio);
    printf("Cantidad de nucleos: %d\n", miPc.cantidad);
}

void copiarPc(compu *miPc, compu listado )
{

    miPc->velocidad = listado.velocidad;
    miPc->anio  = listado.anio;
    miPc->cantidad = listado.cantidad;    
    strcpy(miPc->nombre, listado.nombre);
}