#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float correlacion (float *corr, float *pos, float N, float L, float rho) {
    int i,j,k;
    float dr, Dr;
    Dr = 0.05;
    int *conteo = malloc(L*sizeof(int));
    for (i=0; i<N-2; i++) {
        for (j=i; j<N-1; j++){
            k = 0;
            dr = pow (distancia2 (pos[i],pos[j]), 0.5); //distancia entre partículas
            k = floor (dr/ Dr); //armo el histograma
            conteo [k] += 1; //sumo 1 al valor k en el que corresponde a esa distancia
        }
    }

    for (i=0;i<L;i++){
        corr [i] = conteo[i]/(4*M_PI*Dr*rho*i*i); // i sería la distancia ?
    }
    return 0;
}
