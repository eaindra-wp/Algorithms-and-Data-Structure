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
int partition(int *arr,int p,int q)
{
    int x = arr[p];
    //set the pivot
    int i = p;
    for(int j=p+1; j<=q; j++)
    {
        /*if left pointer is less than the
        pivot value*/
        if(arr[j]<=x)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[p],&arr[i]);
    return i;
}
void L_Quicksort(int *arr,int p,int r)
//conquer
{
    if(p<r)
    {
        int q = partition(arr,p,r);
        L_Quicksort(arr,p,q-1);
        L_Quicksort(arr,q+1,r);
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
    FILE *f1;
    f1 = fopen("RandomH.txt","a");
    srand(time(0));
    clock_t s1,e1;
    double t1;
    for(int i=1; i<=800; i++)
    {
        for(int i=0; i<n; i++)
            arr[i] = rand();
        printf("Before Random...\n");
        print(arr,n);
        s1 = clock();
        L_Quicksort(arr,0,n-1);
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
