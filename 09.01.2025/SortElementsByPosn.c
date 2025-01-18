#include<stdio.h>
void main()
{
    // Sorting Odd positioned Elements
    int n = 7,m,i,j;
    int a[] = {5,2,9,6,1,0,3};
    for(i=1;i<n;i+=2)
    {
        for(j=0;j<n-2;j+=2)
        {
            if(a[j]>a[j+2])
            {
                m=a[j];
                a[j]=a[j+2];
                a[j+2]=m;
            }

        }
    }
    int o;
    printf("The array after sorting odd elemnts : ");
    for(o=0;o<n;o++)
    {
        printf("%d\t",a[o]);
    }
    //Sorting Even Positoned elements
    int evenCount = 0;
    int evenElements[n];
    for(i = 0; i < n; i++)
    {
        if(a[i] % 2 == 0)
        {
            evenElements[evenCount++] = a[i];
        }
    }
    for(i = 0; i < evenCount - 1; i++)
    {
        for(j = 0; j < evenCount - 1 - i; j++)
        {
            if(evenElements[j] > evenElements[j + 1])
            {
                m = evenElements[j];
                evenElements[j] = evenElements[j + 1];
                evenElements[j + 1] = m;
            }
        }
    }
    evenCount = 0;
    for(i = 0; i < n; i++)
    {
        if(a[i] % 2 == 0)
        {
            a[i] = evenElements[evenCount++];
        }
    }
    printf("The array after sorting even elements: ");
    for(i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
}

