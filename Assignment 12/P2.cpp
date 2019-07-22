#include <bits/stdc++.h>
using namespace std;

//the number of characters to be allowed for the input
const int d = 256;
void RabinKarp(char pattern[], char text[], int q)
{
    int m=strlen(pattern); //length of pattern
    int n=strlen(text); //length of text
    int i,j;
    int p=0; //hash value for pattern
    int t=0; // hash value for text
    int h=1;
     //the value of h is "pow(d,m-1)%q"
    for (i=0; i<m-1; i++)
        h =(h*d)%q;

    //calculate the hash value of pattern and text
    //and update until the length of pattern
    for (i = 0; i < m; i++)
    {
        p = (d * p + pattern[i])%q;
        t = (d * t + text[i])%q;
    }

    //shift the pattern by char by char to the right
    for (i=0; i<=n-m; i++)
    {
        //check if hash values of text and pattern are equal
        if (p==t)
        {
            //if yes,then compare the pattern with text character
            //by character starting from the current position of text
            for (j = 0; j<m; j++)
            {
                if (text[i+j] != pattern[j])
                //break if the character becomes different
                    break;
            }
            //print the location of first letter if pattern is found
            //(if pattern[1..m] == text[i+1...i+m])
            if (j==m)
                cout<<"Pattern occurs with shift "<< i <<endl;
        }

        //calculate the new hash value for text
        if (i<n-m)
        {
            t=(d*(t-text[i]*h)+text[i+m])%q;

            //convert the length of text to a positive value
            //if the value received is negative.
            if (t<0)
                t+=q;
        }
    }
}
int main()
{
    char T[] = "THIS IS SWEET S IS S";
    char P[] = "S IS S";
    int q = 101; //define a prime number
    RabinKarp(P,T,q);
    return 0;
}
