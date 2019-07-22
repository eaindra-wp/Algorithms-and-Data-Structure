#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void merge(int *arr,int p,int q,int r)
{
    int n1,n2,i,j,k;
    n1= q-p+1;
    n2= r-q;
    int ll[n1], rr[n2];
    //create temporary arrays
    for(i=0; i<n1; i++)
        ll[i] = arr[p+i];
    //copy elements from left side of array
    for(j=0; j<n2; j++)
        rr[j] = arr[q+j+1];
    //copy elements from right side of array
    i=0;
    j=0;
    k=p;
    /*copy sorted elements from 2 temp arrays to
    the original array in order*/
    while(i<n1 && j<n2)
    {
        //compare each element from two arrays
        if(ll[i] <= rr[j])
        {
            arr[k++] = ll[i++];
        }
        else
        {
            arr[k++] = rr[j++];
        }
    }
    /*copy remaining elements from
    the left side temp array*/
    while(i<n1)
    {
        arr[k++]= ll[i++];
    }
    /*copy remaining elements from
    the right side temp array*/
    while(j<n2)
    {
        arr[k++]= rr[j++];
    }
}
void insertion_sort(int *arr,int p,int r)
{
    //insertion sort for sub-divided arrays
    int key,i,j;
    for (i=p+1; i<=r; i++)
    {
        key= arr[i];
        j= i-1;
        //compare with left adjacent element
        while(j>=p && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
void merge_sort(int *arr,int p,int r,int k)
{
    /*check whether to start insertion sort
    for sub-divided arrays*/
    if(r-p+1<=k)
    {
        insertion_sort(arr,p,r);
    }
    else
    {
        int q = (p+r)/2;//divide
        merge_sort(arr,p,q,k);//conquer
        merge_sort(arr,q+1,r,k);//conquer
        merge(arr,p,q,r);//combine
    }

}
void print_array(int *arr,int n)
{
    //print elements in the array
    for(int i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main()
{
    int n,k,i;
    printf("Type the number of elements:");
    scanf("%d",&n);
    srand(time(0));
    int *arr= (int*)malloc(sizeof(int)*n);
    //dynamically allocate the array
    for (i=0; i<n; i++)
    {
        arr[i]=rand();
    }
    //add random values to the array
    printf("Type the number to be separated:");
    scanf("%d",&k);
    //input value to be divided
    while (k > n)
    {
        printf("Error: the separated number shouldn't");
        printf("be larger than the array's size.\n");
        scanf("%d",&k);
    }
    printf("Before Sorting:\n");
    print_array(arr,n);
    merge_sort(arr,0,n-1,k);
    printf("After Sorting:\n");
    print_array(arr,n);
    free(arr);
    //deallocating the array
    return 0;
}
