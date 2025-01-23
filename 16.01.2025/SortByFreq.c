#include<stdio.h>
int subarraySum(int* nums, int numsSize) {
    int i,j,sum = 0;
    for(i=0;i<numsSize;i++)
    {
        int o = 0;
        int b[numsSize];
        int x = i - nums[i];
        if(x>0)
        {
            for(j=x;j<=i;j++)
            {
                b[o] = nums[j];
                o++;
            }
        }
        else
        {
            for(j=0;j<=i;j++)
            {
                b[o] = nums[j];
                o++;
            }
        }
        for(int u =0;u<=o;u++)
        {
            sum+=b[u];
        }
    }
    return(sum);
}
int main()
{
    int a[] = {2,1,3};
    int n = 3;
    printf("%d",subarraySum(a,n));
}