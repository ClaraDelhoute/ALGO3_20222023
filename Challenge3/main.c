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
               return max=maximun(n-1,t); //return doit se placer ici
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
    Tab t2={9,14,12,11,1,7,5};
     printf("%d",maximun(n, t2));
}
