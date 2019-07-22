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
    int x = arr[(p+q)/2];
    int l = p-1;
    int r = q+1;
    while(1)
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
        }while(arr[r]>x);

       if(l>=r)
        {
            return r;
            break;
        }
        swap(&arr[l],&arr[r]);
    }
}
void H_Quicksort(int *arr,int p,int r)
//conquer
{
    if(p<r)
    {
        int q = partition(arr,p,r);
        //recursively calling the function
        H_Quicksort(arr,p,q);
        H_Quicksort(arr,q+1,r);
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
    int n;
    scanf("%d",&n);
    int arr[n];
    srand(time(0));
    clock_t s1,e1;
    double t1;
    for(int i=0; i<n; i++)
        arr[i] = rand();
    printf("Before Random...\n");
    print(arr,n);
    s1 = clock();
    H_Quicksort(arr,0,n-1);
    e1 = clock()-s1;
    printf("After Random...\n");
    print(arr,n);
    t1 = (double)e1*1000/CLOCKS_PER_SEC;
    printf("It took %lf milliseconds\n",t1);

    return 0;
}
