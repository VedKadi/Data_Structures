#include<stdio.h>
int main()
{
    printf("Enter the size of array : ");
    int n;
    scanf("%d",&n);
    int a[n], i;
    for(i=0;i<n;i++)
    {
        printf("Enter element no. %d : ",i+1);
        scanf("%d",&a[i]);
    }
    /*
    //Traverse
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n\n");
    */
   /*
    //Delete
    printf("To Delete the initial element:0\nfinal element:1\nspecific index:2\n");
    int x;
    scanf("%d",&x);
    if(x==0)
    {
       //At beginning
        int j;
        for(j=0;j<n;j++)
        {
            a[j]=a[j+1];
        }
        n--; 
    }
    else if(x==1)
    {
        //At End
        n--;
    }
    else
    {
        //at Specific index
        int i;
        printf("Enter the Index to delete : ");
        int m;
        scanf("%d",&m);
        for(i=m;i<n;i++)
        {
            a[i]=a[i+1];
        }
        n--;
    }
    int ii;
    for(ii=0;ii<n;ii++)
    {
        printf("%d\t",a[ii]);
    }
    */
   /*
    //To Insert
    printf("To Insert as initial element:0\nfinal element:1\nat specific index:2\n");
    int y,q,b[n+1];
    scanf("%d",&y);
    if(y==0)
    {
        //As Initial element
        printf("Enter the element to insert : ");
        int w,s;
        scanf("%d",&w);
        b[0]=w;
        for(s=1;s<n+1;s++)
        {
            b[s] = a[s-1];
        }
    }
    else if(y==1)
    {
        //as final element
        printf("Enter the element to insert : ");
        int w,s;
        scanf("%d",&w);
        for(s=0;s<n;s++)
        {
            b[s] = a[s-1];
        }
        b[n+1]=w;
    }
    else
    {
        printf("Enter the index to add the element to : ");
        int e,w,s,p;
        scanf("%d",&e);
        printf("Enter the element to add : ");
        scanf("%d",&w);
        for(s=0;s<e;s++)
        {
            b[s] = a[s];
        }
        b[e]=w;
        for(p=e+1;p<n+1;p++)
        {
            b[p]=a[p-1];
        }
    }
    for(q=0;q<n;q++)
    {
        printf("%d\t",b[q]);
    }
    */
    
}