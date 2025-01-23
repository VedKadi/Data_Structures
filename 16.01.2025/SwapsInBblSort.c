//To Calculate No. of Swaps in Bubble Sort
#include<stdio.h>
void copy_array(int a[],int b[],int n)
{
    //Function to copy elements of an array a into array b.
    int i;
    for(i=0;i<n;i++)
    {
        b[i] = a[i];
    }
}
int NoOfSwapsBblSort(int a[], int n)
{
    int b[n];
    copy_array(a,b,n);
    int i,j,m = 0;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(b[j]>b[j+1])
            {
                int temp = b[j];
                b[j] = b[j+1];
                b[j+1] = temp;
                m++;
            }
        }
    }
    return(m);
}
int main()
{
    int Arr[] = {2,7,1,9,0,7,0,5};
    int n=8;
    int x = NoOfSwapsBblSort(Arr,n);
    printf("%d",x);
}