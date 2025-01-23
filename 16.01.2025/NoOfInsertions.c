//To Sort an array using insertion sort and count the no. of times insertion takes place.
/*
#include<stdio.h>
int NoOfInsertions(int a[] ,int n)
{
    int i,j,m=0;
    for(i=1;i<n;i++)
    {
        j = i-1;
        int temp  = a[i];
        while(j>=0 && temp <a[j])
        {
            a[j+1] = a[j];
            j--;
            m++;
        }
        a[j+1] = temp;
    }
    return(m);
}
*/
#include <stdio.h>

int NoOfInsertions(int a[], int n) {
    int i, j, m = 0;
    for (i = 1; i < n; i++) {
        int temp = a[i];
        j = i - 1;
        
        // Shift elements to the right to create space for the current element
        while (j >= 0 && temp < a[j]) {
            a[j + 1] = a[j];  // Shift element
            j--;
            m++;  // Count each shift (insertion)
        }
        
        a[j + 1] = temp;  // Insert the current element into its correct position
    }
    return m;
}


int main()
{
    int Arr[] = {2,7,1,9,0,7,0,5};
    int n=8;
    int x = NoOfInsertions(Arr,n);
    printf("%d",x);
    return(0);
}