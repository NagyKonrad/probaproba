#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define N 12

int main(){
    double tomb[ ] = {289.5, 292.6, 290.2, 295.5, 300.4, 300.3, 302.5, 303.3, 303.5, 299.9};
    int meret=sizeof(tomb)/sizeof(double);
    double limit=300.0;
    int db=0;

    printf("HUF/EUR arfolyamok:\n");
    for(int i=0;i<meret;i++)
    {
        printf("%d. ertek: %.2f \n", i+1, tomb[i]);
        if(tomb[i]<limit)
        {
            db++;
        }
    }
    printf("Az arfolyam erteke %d-szer volt %.2f alatt.", db, limit);
    //monotonitas vizsgalat
    int found=0;
    for (int i=1; i<N && !found; i+=1)
    {
        if (tomb[i] < tomb[i-1])   found=1;
    }
    printf("A sorozat monoton novo: %s", !found ? "igaz" : "hamis");
    //min max
    double min=1000;
    double max=0;
    int minindex=0;
    int maxindex=0;
    for(int i=0;i<meret;i++)
    {
        if(tomb[i]<min)
        {
            min=tomb[i];
            minindex=i+1;
        }
        if(tomb[i]>max)
        {
            max=tomb[i];
            maxindex=i+1;
        }
    }
    printf("\nMinimum: %.2lf a(z) %d. heten.\nMaximum: %.2lf a(z) %d. heten.\n",min,minindex,max,maxindex);
    //atlag+szoras
    double atlag=0;
    for(int i=0;i<meret;i++)
    {
        atlag=atlag+tomb[i];
    }
    atlag=atlag/meret;
    printf("Atlag: %.2lf\n",atlag);
    for(int i=0;i<meret;i++)
    {
        double elteres=fabs(tomb[i]-atlag);
        printf("A(z) %d. heten az elteres: %.2lf\n",i+1,elteres);
        elteres=0;
    }


    return 0;
}