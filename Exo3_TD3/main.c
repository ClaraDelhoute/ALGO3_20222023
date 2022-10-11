#include <stdio.h>
#include <stdlib.h>
#define MAX 150
typedef int Tab[MAX];

void saisie (int n, Tab t)
{
    if(n==0)
    {
        scanf("%d",&t[0]);
    }
    else
    {
        scanf("%d",&t[n]);
        saisie((n-1),t);
    }
}

int somme(int n, Tab t)
{
    if(n==0)
    {
        return t[0];
    }
    else
    {
        return (t[n] + somme((n-1),t));
    }
}

void remplace_occurence(int a, int n,Tab t)
{
    if(t[0] == a)
    {
        t[0]=0;
    }
    else
    {
        if(t[n]==a)
        {
            t[n]=0;
        }
        else
        {
            remplace_occurence(a,(n-1),t);
        }
    }
}

int Trie (int n, Tab t)
{
        while(n !=1)
        {
            if(t[n]>Trie(n-1,t))
            {;
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }



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
                max=maximun(n-1,t);
            }
            else
            {
                return t[n];
            }
        }
        return max;
    }

int minimun(int n, Tab t)
{
    int min;
   if(n==0)
   {
       return t[0];
   }
    else
    {
        if(t[n]>t[n-1])
        {
            min=minimun(n-1,t);
            return min;

        }
        else
            {
            return t[n];
            }

    }

}

void min_max(int n, Tab t)
{
    printf("Le maximun est :%d", maximun(n,t));
    printf("Le minimun est : %d", minimun(n,t));

}

int main()
{
    int n; Tab t;
    Tab t1={6,7,5};
    scanf("%d\n",&n);
    saisie(n,t);
    printf("%d\n",somme(n,t));
    printf("%d\n", somme(n,t1));
    //remplace_occurence(2,n,t);
   // printf("%d\n",Trie(n,t));
    min_max(n,t);


}
