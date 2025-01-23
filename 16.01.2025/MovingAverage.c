#include<stdio.h>
void main()
{
    int i,j,m=7,n=3;
    int o = 0;
    float b[o];
    int a[] = {1,2,3,4,5,6};
    for(i=0;i<=m-n;i++)
    {
        int sum = 0;
        for(j=i;j<n+i;j++)
        {
            sum+=a[j];
        }
        b[o]= sum/n;
        o++;
    }
    int x;
    for(x=0;x<m-n;x++)
    {
        printf("%f\t",b[x]);
    }
}