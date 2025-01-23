//Function to calculate occurence of a numbber in an array
#include<stdio.h>
void Print_Array(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}
void copy_array(int a[],int b[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        b[i] = a[i];
    }
}
void Occurence(int a[],int n)
{
    int m=n;
    int i,j,k,b[m];
    copy_array(a,b,n);
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            if(b[i]==b[j] && i!=j)
            {
                for(k=j;k<m;k++)
                {
                    b[k] = b[k+1];
                }
                m--;
                j--;
            }
        }
    }
    int x,y,z;
    for(x=0;x<m;x++)
    {
        int o=0;
        for(y=0;y<n;y++)
        {
            if(b[x]==a[y])
            {
                o++;
            }
        }
        printf("%d-------->%d\n",b[x],o);
    }

}
void main()
{
    int a[] = {0,4,9,6,2,0,3,4,3,3};
    int n = 10;
    Occurence(a,n);
}