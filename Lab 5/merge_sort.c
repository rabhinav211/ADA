#include<stdio.h>
#include<time.h>
#include <stdlib.h>

void merge(int a[],int l,int m,int high)
{
    int i,h;h=l;i=0;
    int j=m+1;int b[high-l+1];
    while(h<=m && j<=high)
    {
        if(a[h]<=a[j])
        {
            b[i]=a[h];
            h++;
        }
        else
        {
            b[i]=a[j];
            j++;
        }i++;
    }
    if(h<=m)
        for(int k=h;k<m;k++)
    {
        b[i++]=a[k];
    }
    if(j<=high)
        for(int k=j;k<high;k++)
    {
        b[i++]=a[k];
    }
    for(int k=0,j=l;k<=high;k++,j++)
    {
        a[j]=b[k];
    }
}

void mergesort(int a[],int l,int h)
{
    int m;
    if(l<h)
    {
        m=(l+h)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,h);
        merge(a,l,m,h);
    }
}

int main()
{
    clock_t start,end;
    int n;
    printf("Enter the number of array elements:");
    scanf("%d",&n);
    int arr[n];
    srand(time(NULL));
    for (int i=0;i<n;i++)
        arr[i]=rand();
    start=clock();
    mergesort(arr,0,n-1);
    end=clock();
    printf("\nTime taken:%f",((double)(end - start)) / CLOCKS_PER_SEC);
    return 0;
}
