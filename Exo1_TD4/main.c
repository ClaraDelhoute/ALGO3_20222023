#include <stdio.h>
#include <stdlib.h>
typedef int Tab[100];

void affichage(Tab t, int *n)
{
    int i;
    for(i=0;i<*n;i++)
    {
        printf("%d",t[i]);
    }
}
void tri_tab(Tab t, int n)
{
    int temp;
    int i,j;
    for(i=0;i<(n-1);i++)
    {
        for(j=i;j<n;j++)
        {
            if(*(t+i)>*(t+j))
            {
                temp=*(t+i);
                *(t+i)=*(t+j);
                *(t+j)=temp;

            }
        }
    }
}
int dicho(Tab t, int c, int g, int d, int * r) //il faut que le tableau soit trié
{
    tri_tab(t,g);
    int ret= g + (d-g)/2;
    if (t[ret] == c)
    {
        *r=ret;
    }
    else
    {
        if(t[ret] > c)
        {
             dicho(t,c,g,ret,r); // ou return dicho
        }
        else
        {

            if(t[ret] < c)
            {
                 dicho(t,c,ret,d,r);
            }
            else
            {
                return -1;
            }
        }
    }
return;
}


int main()
{
    int r=0;
    printf("%d",r);
    Tab t={2,3,6,7,8,9,5,7};
    //tri_tab(t,7);
   // affichage(t,7);
    dicho(t,7,0,7,&r);
    printf("%d",r);
}
