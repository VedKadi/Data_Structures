#include <stdio.h>
void kth_Largest(int a[], int n, int k) 
{
    int i, j, l, t, s;
    for (l = 0; l < k - 1; l++) 
    {
        int max = a[0]; 
        for (i = 1; i < n; i++) 
        {
            if (a[i] > max) 
            {
                max = a[i];
            }
        }
        for (t = 0; t < n; t++) 
        {
            if (a[t] == max) 
            {
                for (s = t; s < n - 1; s++) 
                {
                    a[s] = a[s + 1];
                }
                n--;  
                break;
            }
        }
    }

    int M = a[0];  
    for (i = 1; i < n; i++) 
    {
        if (a[i] > M) 
        {
            M = a[i];
        }
    }
    printf("The %dth Largest Element in the given array is %d\n", k, M);
}

int main() 
{
    int a[] = {2, 6, 3, 9, 5, 0, 2, 7};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 3;
    kth_Largest(a, n, k);
    return 0;
}
