#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <limits.h>
#include <inttypes.h>
#include <stdint.h>

#define RECURSIVE
#define BOTTOMUP
#define CLOSEDFORM
#define MATRIX

long long int Recursive(int n)
{
    if (n<2)
        return n;
    else
        return (Recursive(n-1)+Recursive(n-2));
}
long long int Bottomup(int n)
{
    if (n==0)
        return 0;
    else
    {
        long long int x,y,z;
        x=0;
        y=1;
        for(int i=2; i<=n; i++)
        {
            z= x+y;
            x= y;
            y= z;
        }
        return z;
    }
}
long long int Closedform(int n)
{
    double g = (1+sqrt(5))/2;
    return round((pow(g,n)/sqrt(5)));
    //applying the formula
}
void multiply(long long int arr[2][2],
              long long int arr2[2][2])
{
    //multiplying the array
    long long int a,b,c,d;
    a =  arr[0][0]*arr2[0][0] + arr[0][1]*arr2[1][0];
    b =  arr[0][0]*arr2[0][1] + arr[0][1]*arr2[1][1];
    c =  arr[1][0]*arr2[0][0] + arr[1][1]*arr2[1][0];
    d =  arr[1][0]*arr2[0][1] + arr[1][1]*arr2[1][1];

    arr[0][0] = a;
    arr[0][1] = b;
    arr[1][0] = c;
    arr[1][1] = d;
}
void power(long long int arr[2][2],
                             int n)
{
    //multiplying the base matrix for n times
    long long int arr2[2][2] = {{1,1},{1,0}};
    if (n==0 || n==1)
        return;
    power(arr,n/2);
    /*divide the number of original matrix
    to be multiplied*/
    multiply(arr,arr);
    if(n%2 != 0)
        multiply(arr,arr2);
}
long long int Matrix(int n)
{
    long long int arr[2][2] = {{1,1},{1,0}};
    if(n==0)
        return 0;
    else
    {
        power(arr,n);
        return arr[0][1];
        //return n result
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    long long int r1,r2,r3,r4;
    time_t s1,e1,s2,e2,s3,e3,s4,e4;
    double t1,t2,t3,t4;
    FILE *f1,*f2,*f3,*f4;
    f1 = fopen("Recursive.txt","a");
    f2 = fopen("Bottomup.txt","a");
    f3 = fopen("Closedform.txt","a");
    f4 = fopen("Matrix.txt","a");

    #ifdef RECURSIVE
    s1 = clock();
    r1 = Recursive(n);
    e1 = clock()- s1;
    t1 = (double)e1/CLOCKS_PER_SEC;
    printf("Recursive Result: %lli\n",r1);
    printf("Time taken: %lf\n",t1);
    fprintf(f1,"%d %lf\n",n,t1);
    #endif //RECURSIVE

    #ifdef BOTTOMUP
    s2 = clock();
    r2 = Bottomup(n);
    e2 = clock()- s2;
    t2 = (double)e2/CLOCKS_PER_SEC;
    printf("Bottom-Up Result: %lli\n",r2);
    printf("Time taken: %lf\n",t2);
    fprintf(f2,"%d %lf\n",n,t2);
    #endif //BOTTOMUP

    #ifdef CLOSEDFORM
    s3 = clock();
    r3 = Closedform(n);
    e3 = clock()- s3;
    t3 = (double)e3/CLOCKS_PER_SEC;
    printf("Closed Form Result: %llu\n",r3);
    printf("Time taken: %lf\n",t3);
    fprintf(f3,"%d %lf\n",n,t3);
    #endif // CLOSEDFORM

    #ifdef MATRIX
    s4 = clock();
    r4 = Matrix(n);
    e4 = clock()- s4;
    t4 = (double)e4/CLOCKS_PER_SEC;
    printf("Matrix Form Result: %lli\n",r4);
    printf("Time taken: %lf\n",t4);
    fprintf(f4,"%d %lf\n",n,t4);
    #endif // MATRIX

    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);
    return 0;
}
