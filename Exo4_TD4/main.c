#include <stdio.h>
#include <stdlib.h>
#define MAX 250
typedef int Tab[MAX];


void fusion(Tab t,int debut,int m,int fin)
{
    int i=debut, j=m+1, k=0;
    Tab res;
    while((i<=m) && (j<=fin))
    {
        if(*(t+i)<*(t+j))
        {
            *(res+k)=*(t+i);
            i++;
        }
        else
        {
            *(res+k)=*(t+j);
            j++;
        }
        k++;
    }
    while(i<=m)
    {
        *(res+k)=*(t+i);
        i++;
        k++;
    }
    while(j<=fin)
    {
        *(res+k)=*(t+j);
        j++;
        k++;
    }
    for(k=0;k<fin-(debut+1);k++)
    {
        *(t+(debut+fin))=*(res+k);
    }
}
void triFusion( Tab t, int debut, int fin)
{
    int m;
    if(debut<fin)
    {
        m=(debut+fin)/2;
        triFusion(t,debut,m);
        triFusion(t,m+1,fin);
        fusion(t,debut,m,fin);
    }
}

void affiche(Tab t, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf(" %d ",*(t+i));
    }
}
int main()
{
    Tab t={3,17,9,15,2,7,10,9,8,12};
    Tab t2={5,8,12,4,7,32,2};
    int longueur2=7;
    int longueur=9;
    affiche(t,longueur);
    triFusion(t,0,longueur);
    printf("\n");
    affiche(t,longueur);
    printf("\n");
    affiche(t2,longueur2);
    triFusion(t2,0,longueur2);
    printf("\n");
    affiche(t2,longueur2);


}
