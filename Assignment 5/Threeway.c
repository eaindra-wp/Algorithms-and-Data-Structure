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
void partition(int* arr,int s,int e,int* l,int* r)
{
    swap(&arr[s+1],&arr[e]);
    /*swap the rightmost element and second element
    so the second element becomes the right pivot*/
    if(arr[s]>arr[e])
    {
        swap(&arr[s],&arr[e]);
    }
    int ll = s+1;
    int rr = e-1;
    int i = s+1;
    int p = arr[s];
    int q = arr[e];
    //set the pivots
    while(i<=rr)
    {
        if(arr[i]<p)
        //check if the element is smaller than the first pivot
        {
            swap(&arr[i],&arr[ll]);
            ll++;
        }
        else if(arr[i]>=q)
        /*check if the element is larger than or
        equal to the second(rightmost) pivot*/
        {
            while(arr[rr]>q && i<rr)
            {
                rr--;
            }
            swap(&arr[i],&arr[rr]);
            rr--;
            if(arr[i]<p)
            {
                swap(&arr[i],&arr[ll]);
                ll++;
            }
        }
        i++;
        //move the left pointer inwards
    }
    ll--;
    //move the left pointer outwards
    rr++;
    //set pivots back at appropriate positions
    swap(&arr[s],&arr[ll]);
    swap(&arr[e],&arr[rr]);
    //return the position of pivots
    *l = ll;
    *r = rr;
}
void T_Quicksort(int *arr,int s,int e)
{
    if(s<e)
    {
        int l,r;
        partition(arr,s,e,&l,&r);
        //calling the partition function
        T_Quicksort(arr,s,l-1);
        T_Quicksort(arr,l+1,r-1);
        T_Quicksort(arr,r+1,e);
        //recursively sorting sub arrays
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
    T_Quicksort(arr,0,n-1);
    e1 = clock()-s1;
    printf("After Random...\n");
    print(arr,n);
    t1 = (double)e1*1000/CLOCKS_PER_SEC;
    printf("It took %lf milliseconds\n",t1);
    return 0;
}
