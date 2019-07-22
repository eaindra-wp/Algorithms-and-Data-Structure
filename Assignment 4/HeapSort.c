#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void maxHeapify(int *arr,int n,int i)
{
    //set root as largest
    int largest = i;
    int l = (2*i)+1;
    int r = (2*i)+2;
    //create left and right nodes
    int swap;

    /*if the left child is larger than
    root,set largest to the left*/
    if(l<n && arr[l]>arr[i])
        largest = l;
    else
        largest = i;

    /*if the right child is larger than
    root,set largest to the right*/
    if(r<n && arr[r]>arr[largest])
        largest = r;

    /*if largest is not the root,swap
    the root and largest*/
    if(largest != i)
    {
        swap = arr[i];
        arr[i] = arr[largest];
        arr[largest] = swap;
        maxHeapify(arr,n,largest);
        //recursively heapify
    }
}
/*call max-heap function from the lowest
node*/
void buildMaxHeap(int *arr,int n)
{
    for(int i=(n/2)-1; i>=0; i--)
    {
        maxHeapify(arr,n,i);
    }
}
/*build the heap first and
swap the last element with the
first element,and decrement the
heap size and call maxheap,removing
the last element in the array*/
void heapSort(int *arr,int n)
{
    int swap,count;
    count = n;
    buildMaxHeap(arr,n);
    for(int i= n-1; i>=1; i--)
    {
        swap = arr[0];
        arr[0] = arr[i];
        arr[i] = swap;
        count--;
        maxHeapify(arr,count,0);
    }
}
//print the array
void print(int *arr,int n)
{
    for(int i=0; i<n; i++)
        printf("%d ",arr[i]);
    printf("\n");
}
int main()
{
    FILE *fp;
    fp = fopen("HeapSort.txt","a");
    int n,i;
    clock_t s,e;
    scanf("%d",&n);
    int arr[n];
    srand(time(0));
    for(i=0; i<n; i++)
        arr[i]= rand();
    printf("Before sorting...\n");
    print(arr,n);
    printf("After sorting...\n");
    //measure the time
    s = clock();
    heapSort(arr,n);
    e = clock()- s;
    double t = 1000*((double)e)/CLOCKS_PER_SEC;
    print(arr,n);
    printf("It takes %lf milliseconds\n",t);
    fprintf(fp,"%d %lf\n",n,t);
    fclose(fp);
    return 0;
}
