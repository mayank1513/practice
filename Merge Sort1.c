#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define N 50000

mergesort(int a[], int low, int high);
merge(int a[], int low, int high, int mid);

int main()
{
    int s[N],i,j;
    FILE *fp;
    float t1,t2;

    srand(GetTickCount());

    fp=fopen("input2.txt","r");

    for(i=0;i<N;i++)
        fscanf(fp,"\n%d",&s[i]);

    fclose(fp);
    t1=GetTickCount();

    mergesort(s,0,N);

    t2=GetTickCount();

    fp=fopen("TimeComplexity.txt","w");

    fprintf(fp,"\nMergr sorting of %d numbers took %fmsec.",N,t2-t1);

    //for(i=0;i<100;i++)
      // printf("\n%d",s[i]);
}

mergesort(int a[], int low, int high)
{
int mid;
if(low<high)
{
mid=(low+high)/2;
mergesort(a,low,mid);
mergesort(a,mid+1,high);
merge(a,low,high,mid);
}
return(0);
}

merge(int a[], int low, int high, int mid)
{
int i, j, k, c[N];
i=low;
j=mid+1;
k=low;
while((i<=mid)&&(j<=high))
{
if(a[i]<a[j])
{
c[k]=a[i];
k++;
i++;
}
else
{
c[k]=a[j];
k++;
j++;
}
}
while(i<=mid)
{
c[k]=a[i];
k++;
i++;
}
while(j<=high)
{
c[k]=a[j];
k++;
j++;
}
for(i=low;i<k;i++)
{
a[i]=c[i];
}
}
