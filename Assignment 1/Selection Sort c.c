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
    clock_t s1,s2,s3,e1,e2,e3;
    double t1,t2,t3;
    printf("Enter the number of elements: ");
    scanf("%d", &x);
    int arr[x],arr2[x],arr3[x];

    //Sorting an random array to produce the average case
    printf("Random Unsorted Array: \n");
    srand(time(0));
    for (int i=0;i<x;i++)
    {
        arr[i] = rand();
        printf("%d ",arr[i]);
    }
    //start selection sort
    s1 = clock();
    SelectionSort(arr,x);
    e1 = clock()-s1;
    //end selection sort
    printf("\nSelection Sort Random result: \n");
    result(arr,x);
    t1 = (1000*(double)e1)/CLOCKS_PER_SEC;
    printf("It took %lf milliseconds to sort randomly.\n\n", t1);


    //Best case
    printf("Best case sort started...\nBefore Sorting\n");
    for (int i=0;i<x;i++)
    {
        arr2[i] = arr[i];
        printf("%d ",arr2[i]);
    }
    s2 = clock();
    SelectionSort(arr2,x);
    e2 = clock()-s2;
    printf("\nSelection Sort Best case result: \n");
    result(arr2,x);
    t2 = (1000*(double)e2)/CLOCKS_PER_SEC;
    printf("It took %lf milliseconds to sort for the best case.\n\n", t2);


    //Worst case
    printf("Worst case sort started...\nBefore Sorting\n");
    for (int j=0; j<x; j++)
    {
        arr3[j] = arr[x-1-j];
        printf("%d ",arr3[j]);
    }
    printf("\n");
    s3= clock();
    SelectionSort(arr3,x);
    e3 = clock()-s3;
    printf("Selection Sort Worst case result: \n");
    result(arr3,x);
    t3 = (1000*(double)e3)/CLOCKS_PER_SEC;
    printf("It took %lf milliseconds to sort for the worst case.\n", t3);

    return 0;
}

