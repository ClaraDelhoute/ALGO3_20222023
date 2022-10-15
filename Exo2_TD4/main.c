#include <stdio.h>
#include <stdlib.h>
typedef int Tab[100];

int retourne_indice(int debut, int fin, Tab t)
{
    int i;
    int indice_min=debut;
    for(i=debut;i<fin;i++)
    {
        if(*(t+i)<*(t+indice_min))
        {
            indice_min=i;
        }
    }
    return indice_min;
}

void permute(Tab t, int i, int j)
{
    int temp=*(t+i);
    *(t+i)=*(t+j);
    *(t+j)=temp;
}

void tri_tab(Tab t,int n)
{
    int i;
    int occ=0;
    int m;
    for(i=0;i<n;i++)
    {
         m=retourne_indice(i,n,t);
        if( m != i )
        {

            permute(t,i,m);
            occ++;
        }
    }
    printf("Le nombre d'occurence est : %d\n",occ);
}

int affiche_tab(Tab t, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf(" %d ",*(t+i));
    }
}

//Exercice 3

void f(Tab t, int n)
{
    int occ=0;
    int b=1, j=n,i;
    while(b==1)
    {
        b=0;
        i=0;
        while(i<j)
        {
            if(*(t+i)>*(t+(i+1)))
            {
                permute(t,i,i+1);
                occ++;
                b=1;
            }
            i++;
        }
        j--;
    }
    printf("Le nombre d'occurence est de %d\n",occ );
}
int main()
{
    Tab t1  ={1,0,4,6,3,7,4};
    printf("%d\n",retourne_indice(0, 7,t1));
    Tab t2 = {3,17,9,15,2,7,10,9,8,12};
    printf("%d\n", retourne_indice(0,10,t2));
    tri_tab(t2,10);
    affiche_tab(t2,10);
    printf("\n");
    f(t2,10);
    affiche_tab(t2,10);
}

