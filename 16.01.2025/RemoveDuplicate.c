#include<stdio.h>
void RemoveDuplicates(int a[],int n)
{
    //Function to remove duplicate elements from an array of integers and print it. 
    int i,j,k;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i]==a[j] && i!=j)
            {
                for(k=j;k<n;k++)
                {
                    a[k] = a[k+1];
                }
                n--;
                j--;
            }
        }
    }
    int u;
    for(u=0;u<n;u++)
    {
        printf("%d\t",a[u]);
    }
}
void main()
{
    int a[] = {1,5,1,3,6,8,3,4,3};
    int n = 9;
    RemoveDuplicates(a,n);
}