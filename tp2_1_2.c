#include <stdio.h>
#include <stdlib.h>
#define N 20

int main()
{
    int i;
    double vt[N];
    double *p = vt;

    
    for(i = 0;i<N; i++)
    {
        *p=1+rand()%100;
        printf("%f ", *p);
        p++;
    }
    return 0;
}