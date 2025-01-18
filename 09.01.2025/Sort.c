#include<stdio.h>
void main()
{
    int n;
    printf("Enter the size of the array : ");
    scanf("%d",&n);
    int i,m,j,k,a[n];
    printf("Enter the array : ");
    for(k=0;k<n;k++)
    {
        scanf("%d",&a[k]);
    }
    //sorting
    for(i=1;i<n-1;i+=2)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                m=a[j];
                a[j]=a[j+1];
                a[j+1]=m;
            }

        }
    }
    int o;
    printf("The sorted array is : ");
    for(o=0;o<n;o++)
    {
        printf("%d\t",a[o]);
    }
}