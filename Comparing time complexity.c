#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

#define N 10000

void InsertionSort(void);
void SelectionSort(void);
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

    fprintf(fp,"\n\nTheoretical Time compexity of Merge Sort is n*log(n)=%f",N*log(N));

    SelectionSort();
    InsertionSort();

    //for(i=0;i<100;i++)
      // printf("\n%d",s[i]);
}

void InsertionSort(void)
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

    fprintf(fp,"\n\n\nInsertion sorting of %d numbers took %fmsec.",N,t2-t1);

    fprintf(fp,"\n\nTheoretical Time compexity of Insertion Sort is n*n,(for worst case)=%d",N*N);

}


void SelectionSort(void)
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

    fprintf(fp,"\n\n\nSelection Sorting of %d numbers took %fmsec",N,t2-t1);

        fprintf(fp,"\n\nTheoretical Time compexity of Selection Sort is n^2=%d",N*N);
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
