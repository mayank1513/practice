#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

#define N 10000


int main()
{
    int s[N],i,j,x;
    FILE *fp;
    float t1,t2;

    srand(GetTickCount());

    fp=fopen("input2.txt","r");

    for(i=0;i<N;i++)
        fscanf(fp,"\n%d",&s[i]);

    fclose(fp);
    t1=GetTickCount();

    for(i=0;i<N;i++)
    {
        x=s[i];
        for(j=i-1;j>=0;j--)
        {
            if(x<s[j])
            {
                s[j+1]=s[j];
                s[j]=x;
            }
        }
    }

    t2=GetTickCount();

    fp=fopen("TimeComplexity.txt","a");

    fprintf(fp,"\nInsertion sorting of %d numbers took %fmsec.",N,t2-t1);

    fprintf(fp,"\n\nTheoretical Time compexity of Insertion Sort is n*n,(for worst case)=%f",N*N);

}
