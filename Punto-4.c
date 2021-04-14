#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    int velocidad;
    int anio;
    int cantidad;
    char nombre[10];
}compu;

void mostrar(compu *);
void mostrarArreglo(compu *, int);
void cargar(compu *);
void cargarArreglo(compu *, int);
void pcMasVieja(compu *, int);
void pcMasVelos(compu *, int);

int main() {
    srand (time(NULL));
    compu *cantidadPc;
    int cantidad;
    printf("Ingrese la cantidad de pc a guardar: ");
    scanf("%d", &cantidad);

    cantidadPc = (compu *) malloc(sizeof(compu) * cantidad);
    cargarArreglo(cantidadPc ,cantidad );
    mostrarArreglo(cantidadPc , cantidad);
    pcMasVieja(cantidadPc,cantidad);
    pcMasVelos(cantidadPc, cantidad);

    return 0;
}


void cargar(compu *cantidadPc)
{
    cantidadPc->velocidad = rand() % 3 + 1 ; 
    cantidadPc->anio = rand() % 18 + 2000;
    cantidadPc->cantidad = rand() % 4 + 1;

    char tipos[6][10]={"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    
    int ran = rand() % 6 ;
 
     for (int i = 0; i < '\0'; i++)
     {
         cantidadPc->nombre[i] = tipos[ran][i];
     }

}

void cargarArreglo(compu *puntero, int cantidad){

    for (int i = 0; i < cantidad; i++)
    {
        cargar(puntero);
        puntero++;
    }
}

void mostrar(compu *puntero)
{
    printf("------------------------------------\n");
    printf("Velocidad: %d Gherz\n",puntero->velocidad);
    printf("Año: %d\n", puntero->anio);
    printf("Cantidad de nucleos: %d\n", puntero->cantidad);

    for (int i = 0; i < '\0'; i++)
    {
        printf("Nombre: %c\n",puntero->nombre[i]);
    }
       printf("Nombre: %s\n",puntero->nombre); 
}

void mostrarArreglo( compu *puntero, int cantidad){

    for (int i = 0; i < cantidad; i++)
    {
        mostrar(puntero);
        puntero++;
    }
}

void pcMasVieja( compu *puntero , int cantidad){

   int aux = puntero->anio;

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

void pcMasVelos( compu *puntero, int cantidad)
{
    int aux = puntero->velocidad;
    for (int i = 0; i < cantidad; i++)
    {
        if (aux < puntero->velocidad)
        {
            aux = puntero->velocidad;
        }
        puntero++;     
    }
    printf("\nPc mas veloz: %d", aux);
}