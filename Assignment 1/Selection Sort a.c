#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//swapping two numbers if needed
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SelectionSort(int arr[], int x)
{
    int i,j,min;
    for(i=0; i<x-1; i++)
    {
        min = i;
        for(j=i+1; j<x; j++)
        {
            //compare with the element in the right side
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            swap(&arr[i],&arr[min]);
        }
    }
}

void result(int arr[], int x)
{
    int i;
    for (i=0; i<x; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int x;
    double t;
    clock_t start, end;
    printf("Enter the number of elements: ");
    scanf("%d", &x);
    int arr[x];
    printf("Random Unsorted Array: \n");
    for (int i=0;i<x;i++)
    {
        arr[i] = rand();
        printf("%d ",arr[i]);
    }
    //selection sort start
    start = clock();
    SelectionSort(arr,x);
    end = clock()-start;
    //selection sort ends
    printf("\nSelection Sort result: \n");
    result(arr,x);
    t = ((double)end)/CLOCKS_PER_SEC;
    printf("It took %lf seconds to sort all numbers.\n", t);
    return 0;
}
