#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *a,int *b)
//swap two integers
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int median(int *arr,int p,int q)
{
    int m = (p+q)/2;
    /*swap the numbers to find the
    real median number*/
    if(arr[p]>arr[m])
        swap(&arr[p],&arr[m]);

    if(arr[p]>arr[q])
        swap(&arr[p],&arr[q]);

    if(arr[q]>arr[m])
        swap(&arr[m],&arr[q]);

    //return the true median value
    return arr[q];
}
int partition(int *arr,int p,int q)
{
    int x = median(arr,p,q);
    //set the pivot
    int l = p-1;
    int r = q;
    while(l<r)
    {
        //point to lower index
        do
        {
            l++;
        }while(arr[l]<x);

        //point to higher index
        do
        {
            r--;
        }while(r>0 && arr[r]>x);

        if(l>=r)
            break;
        else
            swap(&arr[l],&arr[r]);
    }
    swap(&arr[l],&arr[q]);
    //return the location of true median
    return l;
}
void M_Quicksort(int *arr,int p,int r)
//conquer
{
    if(p<r)
    {
        int q = partition(arr,p,r);
        M_Quicksort(arr,p,q-1);
        M_Quicksort(arr,q+1,r);
    }
}
void print(int *arr,int n)
{
    for (int i=0; i<n; i++)
        printf("%d ",arr[i]);
    printf("\n");
}

int main()
{
    int n=1000;
    int arr[n];
    srand(time(0));
    clock_t s1,e1;
    double t1;
    FILE *f1;
    f1 = fopen("RandomM.txt","a");
    for(int i=1; i<=800; i++)
    {
        for(int i=0; i<n; i++)
            arr[i] = rand();
        printf("Before Random...\n");
        print(arr,n);
        s1 = clock();
        M_Quicksort(arr,0,n-1);
        e1 = clock()-s1;
        printf("After Random...\n");
        print(arr,n);
        t1 = (double)e1*1000/CLOCKS_PER_SEC;
        printf("It took %lf milliseconds\n",t1);
        fprintf(f1,"%lf\n",t1);
    }
    fclose(f1);
    return 0;
}
