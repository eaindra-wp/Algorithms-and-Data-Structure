#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void BubbleSort(int *arr,int n)
{
    int i,j,k,swap;
    for(i=0; i<n-1; i++)
    {
        //check if adjacent swap is needed
        swap= 0;
        /*decrement the number of indexes
        to be visited in order to ignore sorted
        largest elements on the right side
        of array*/
        for(j=0; j<n-i-1; j++)
        {
            /*swap if two adjacent elements are
            in wrong order.*/
            if(arr[j]>arr[j+1])
            {
                //swap two adjacent elements
                k = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = k;
                swap = 1;
            }
        }
        /*After each inner loop,the largest element
        will be sent to the last position in the array.But
        other elements may not in the correct
        order.So,we have to check other remaining elements
        on the left side of array*/
        if(swap == 0)
            /*if two elements are not swapped anymore
            in the inner loop,then the sorting process
            is finished.*/
            break;
    }
}
//print elements in the array
void print(int *arr,int n)
{
    for(int i=0; i<n; i++)
        printf("%d ",arr[i]);
    printf("\n");
}
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n],arr2[n],arr3[n];
    clock_t s1,e1,s2,e2,s3,e3;
    double t1,t2,t3;
    FILE *f1,*f2,*f3;
    f1 = fopen("Random.txt","a");
    f2 = fopen("Best.txt","a");
    f3 = fopen("Worst.txt","a");
    srand(time(0));
    //add random values to the array
    for(int i=0; i<n; i++)
        arr[i] = rand();
    printf("Before Sorting Random...\n");
    print(arr,n);
    s1 = clock();
    BubbleSort(arr,n);
    e1 = clock()- s1;
    t1 = 1000*(double)e1/CLOCKS_PER_SEC;
    printf("After Sorting Random...\n");
    print(arr,n);
    printf("It takes %lf milliseconds./n",t1);
    fprintf(f1,"%d %lf\n",n,t1);

    for(int i=0; i<n; i++)
        arr2[i] = arr[i];
    printf("Before Sorting Best...\n");
    print(arr2,n);
    s2 = clock();
    BubbleSort(arr2,n);
    e2 = clock()- s2;
    t2 = 1000*(double)e2/CLOCKS_PER_SEC;
    printf("After Sorting Best...\n");
    print(arr2,n);
    printf("It takes %lf milliseconds.\n\n",t2);
    fprintf(f2,"%d %lf\n",n,t2);

    for(int i=0; i<n; i++)
        arr3[i] = arr[n-i-1];
    printf("Before Sorting Worst...\n");
    print(arr3,n);
    s3 = clock();
    BubbleSort(arr3,n);
    e3 = clock()- s3;
    t3 = 1000*(double)e3/CLOCKS_PER_SEC;
    printf("After Sorting Worst...\n");
    print(arr3,n);
    printf("It takes %lf milliseconds.\n\n",t3);
    fprintf(f3,"%d %lf\n",n,t3);

    fclose(f1);
    fclose(f2);
    fclose(f3);
    return 0;
}
