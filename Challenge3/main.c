#include <stdio.h>
#include <stdlib.h>
typedef int Tab[100];
int maximun(int n, Tab t)
{   int max;
    if  (n==0)
    {
        return t[0];
    }
        else
        {
            if(t[n]<t[n-1])
            {
               return max=maximun(n-1,t);
            }
            else
            {
                return t[n];
            }
        }
}

    int main()
{
    int n; Tab t;
    Tab table={8,9,7};
     n = 3;
    printf("%d",maximun(n, table));
}
