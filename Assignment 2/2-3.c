#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
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
    clock_t s1,e1,s2,e2,s3,e3;
    double t1,t2,t3;
    FILE *fsave;
    srand(time(0));
    fsave = fopen("Data(c).txt","a");
    printf("Type the number of elements:");
    scanf("%d",&n);
    int *arr= (int*)malloc(sizeof(int)*n);
    int *arr2= (int*)malloc(sizeof(int)*n);
    int *arr3= (int*)malloc(sizeof(int)*n);
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
    printf("Before Sorting Random:\n");
    print_array(arr,n);
    s1 = clock();
    merge_sort(arr,0,n-1,k);
    e1 = clock()-s1;
    //record time taken of sorting
    t1= 1000*(double)e1/CLOCKS_PER_SEC;
    printf("After Sorting Random:\n");
    print_array(arr,n);
    printf("Time taken in millisecond: %lf\n",t1);

    for (i=0; i<n; i++)
    {
        arr2[i] = arr[i];
    }
    printf("Before Sorting Best:\n");
    print_array(arr2,n);
    s2 = clock();
    merge_sort(arr2,0,n-1,k);
    e2 = clock()-s2;
    //record time taken of sorting
    t2= 1000*(double)e2/CLOCKS_PER_SEC;
    printf("After Sorting Best:\n");
    print_array(arr2,n);
    printf("Time taken in millisecond: %lf\n",t2);

    for (i=0; i<n; i++)
    {
        arr3[i] = arr[n-i-1];
    }
    //divide(arr3,n);
    printf("Before Sorting Worst:\n");
    print_array(arr3,n);
    s3 = clock();
    merge_sort(arr3,0,n-1,k);
    e3 = clock()-s3;
    //record time taken of sorting
    t3= 1000*(double)e3/CLOCKS_PER_SEC;
    printf("After Sorting Worst:\n");
    print_array(arr3,n);
    printf("Time taken in millisecond: %lf\n",t3);

    fprintf(fsave,"%d %d %lf %lf %lf\n",n,k,t1,t2,t3);
    //save the record in the text file
    fclose(fsave);
    free(arr);
    free(arr2);
    free(arr3);
    //deallocating the array
    return 0;
}
