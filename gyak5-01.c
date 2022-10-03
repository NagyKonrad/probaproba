#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MERET 5

int main(){
    int tomb [MERET];

    for(int i=0;i<MERET;i++)
    {
        tomb[i]=2*i;
        printf("A %d. eleme: %d\n",i+1,tomb[i]);
    }
return 0;
}