#include <stdio.h>
#include <stdlib.h>

#define N 100000

int main()
{
    unsigned s,i;
    FILE *fp;

    fp=fopen("input2.txt","w");

    for(i=0;i<N;i++)
    {
        s=i+rand()*i+rand()*rand();
        fprintf(fp,"\n%d",s);
    }
    fclose(fp);
}
