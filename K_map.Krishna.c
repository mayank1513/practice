#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <stdlib.h>

int **K_map;// **K_map1;
int **Gray;

main()
{
    int n,N,m1,m2,M1,M2,if1,id1;
    int *f,*d;
    int **Binary;
    int i, j,N1;
    FILE *fp;

    printf("\nEnter number of variables");
    scanf("%d",&n);

    N=pow(2,n);     m2=n/2;     m1=n-m2;    M2=pow(2,m2);       M1=pow(2,m1);

    printf("\n No. of Variables, n=%d,N=2^n=%d\n",n,N);

    if(n==0) {printf("Sorry!! You have entered n=0!");  return;}
  //*************************************************************************Memory allocation************************************************
    f=(int *)calloc(N,sizeof(int));
    if(f==NULL) printf("\n1.sufficient memory not avilable!!\n");

    d=(int *)calloc(N,sizeof(int));
    if(d==NULL) printf("\2.nsufficient memory not avilable!!\n");

    K_map=(int **)malloc(M1*sizeof(int *));
    if(K_map==NULL) printf("\3.nsufficient memory not avilable!!\n");

    for(i=0;i<M1;i++)
    {
        K_map[i]=(int *)calloc(M2,sizeof(int));
        if(K_map[i]==NULL) printf("\n4.sufficient memory not avilable!!\n");
    }

/*    K_map1=(int **)malloc((2*M1+1)*sizeof(int *));
    if(K_map1==NULL) printf("\nKmap1.sufficient memory not avilable!!\n");

    for(i=0;i<(2*M1+1);i++)
    {
        K_map1[i]=(int *)calloc((2*M2+1),sizeof(int));
        if(K_map[i]==NULL) printf("\nK_map1.sufficient memory not avilable!!\n");
    }*/

    Binary=(int **)malloc(N*sizeof(int *));
    if(Binary==NULL) printf("\nBinary.sufficient memory not avilable!!\n");

    for(i=0;i<N;i++)
    {
        Binary[i]=(int *)calloc(n,sizeof(int));
        if(Binary[i]==NULL) printf("\nBinary.sufficient memory not avilable!!\n");
    }

    Gray=(int **)malloc(N*sizeof(int *));
    if(Gray==NULL) printf("\nGray.sufficient memory not avilable!!\n");

    for(i=0;i<N;i++)
    {
        Gray[i]=(int *)calloc(n,sizeof(int));
        if(Gray[i]==NULL) printf("\nGray.sufficient memory not avilable!!\n");
    }
//*************************************************************Memory allocation done*****************************************

    for(i=0;i<N;i++)//*********************************************************************************initializing arrayas to 0
        f[i]=d[i]=0;

    fp=fopen("Bullionexp1.txt","r");//###################################################opening input file

    for(i=0;;i++)//**********************************************************************************Reading from input file Bullionexp1.txt
    {
        fscanf(fp,"%d",&f[i]);
        if(f[i]==-1)
        break;
    }

    if1=i;//if1-->max count of f[] should not be varied durinng program execution

    for(i=0;;i++)//**********************************************************************************Reading from input file Bullionexp1.txt
    {
        fscanf(fp,"%d",&d[i]);
        if(d[i]==-1)
        break;
    }

    id1=i;

    fclose(fp);

    mergesort(f,0,if1-1);
    mergesort(d,0,id1-1);

    for(i=0;i<if1;i++)
    {
        for(j=0;j<n;j++)
        {
            Binary[i][j]=f[i]%2;
            f[i]/=2;
        }
    }//Bs obtained

    for(i=0;i<if1;i++)
    {
        Gray[i][n-1]=Binary[i][n-1];
        for(j=n-2;j>=0;j--)
            Gray[i][j]=Binary[i][j]+Binary[i][j+1];
    }
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
int i, j, k, c[10000];
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
