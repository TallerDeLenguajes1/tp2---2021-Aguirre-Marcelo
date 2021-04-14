#include <stdio.h>
#define N 4
#define M 5

int main() {
    int i,f;
    double mt[N][M];

    double *punt = &mt[0][0];
    
    for(i = 0;i<N; i++)
    {
            for(f = 0;f<M; f++)
            {
                 printf("%lf", *(punt + i * M + f));
            }
     printf("\n");
    }
    return 0;
}