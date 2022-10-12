#include <stdio.h>
#include <stdlib.h>
typedef int Tab[100];


void tri_tab(Tab t, int *n)
{
    int *temp;
    int i,j;
    for(i=0;i<*(n-1);i++)
    {
        for(j=i;j<*n;j++)
        {
            if(t[i]>t[j])
            {
                *temp=t[i];
                t[i]=t[j];
                t[j]=*temp;

            }
        }
    }
}
int dicho(Tab t, int *c, int *g, int *d,int *r) //il faut que le tableau soit trié
{
    *r=*(t+((*g+*d)/2));
    if (*(t+*r)==*c)
    {
        return *r;
    }
    else
    {
        if(*c<*(t+*r))
        {
            dicho(t,&c,&g,&r,&r);
            return *r;
        }
        else
        {

        if(*c>*(t+*r))
        {
            dicho(t,&c,&r,&d,&r);
            return *r;
        }
        else
        {
            return -1;
        }
    }
}
}

int main()
{
    int *r=0;
    Tab t={2,3,6,7,8,9,5,7};
    tri_tab(t,7);
    printf("%d",dicho(t,9,0,7,&r));
}
