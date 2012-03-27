#include <stdio.h>
#include <windows.h>

# define N 10000
void SlectionSort(void)
{
    int a[N],i,j,k,x;
    float t1,t2;
    FILE *fp;

    srand(GetTickCount());//Seed no. generator?

    fp=fopen("TimeComplexity.txt","a");

    t1=GetTickCount();
    for(i=0;i<N;i++)
    {
        x=a[i];
        for(j=i+1;j<N;j++)
        {
            if(a[j]<x)
            {
                x=a[j];
                k=j;
            }
        }
        a[k]=a[i];
        a[i]=x;
    }

    t2=GetTickCount();

    fprintf(fp,"\nSelection Sorting of %d numbers took %fmsec",N,t2-t1);
}
