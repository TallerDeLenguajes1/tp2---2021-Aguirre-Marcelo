#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand (time(NULL));

    int par, impar, aux;
     
    int filas = 15;
    int columnas = rand() % 11 + 5 ;
    int arre[filas][columnas];
    int vect[15];

    int *punt = &arre[0][0];
    printf("Cantidad de filas :%d \n", filas);
    printf("Cantidad de columnas :%d \n", columnas);

    printf("---------------------------------\n");



    for ( int i = 0; i < filas; i++)
    {
        par = 0;  // establesco valor cero para que al iniciar  una fila se reinicie el contador par 
        for (int j = 0; j < columnas; j++)
        {
            *(punt + i * columnas + j) =rand() % 1000 ;
            printf("%4d ", *(punt + i * columnas + j));

            aux =  *(punt + i * columnas + j);

            if (0==(aux%2))
            {
                par++;
            }      
        }
        vect[i]= par;   
     printf("\n");     
    }
    printf("---------------------------------\n");
    for (int i = 0; i < filas; i++)
    {
        
        printf("Cantidad de numeros pares en la fila %d: %d\n", i+1 , vect[i]);
    }
         
    return 0;
}
 