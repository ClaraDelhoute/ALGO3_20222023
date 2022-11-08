#include <stdio.h>
#include <stdlib.h>
#define MA
typedef int Tab[100];

void permute(Tab t, int i, int j)
{
    int temp;
    temp=t[i];
    t[i]=t[j];
    t[j]=temp;
}
int partitionner ( Tab t, int debut ,int fin)
{
    int p=t[debut];
    int i = debut - 1 ;
    int j=fin + 1  ;
    int fini = 0;
    while (!fini)
    {
       do{i++;} while(t[i]<p); //On partitionne les éléments <pivot
       do{j=(j-1);} while(t[j]>=p ); // On partitionne les éléments >=pivot
       if(i<j)
        {
            permute(t,i,j);
        }
        else
            {
                fini =1;
            }

    }
    return j;
}

int partitionner2 ( Tab t, int debut ,int fin)
{
    int p=t[(debut+fin)/2];
    int i = debut - 1 ;
    int j=fin + 1  ;
    int fini = 0;
    while (!fini)
    {
       do{i++;} while(t[i]<p); //On partitionne les éléments <pivot
       do{j=(j-1);} while(t[j]>=p ); // On partitionne les éléments >=pivot
       if(i<j)
        {
            permute(t,i,j);
        }
        else
            {
                fini =1;
            }

    }
    return j;
}



void triRapide(Tab t, int debut, int fin)
{
    int p; // pivot
    if(debut<fin)
    {
        p=partitionner(t,debut,fin);
        triRapide(t,debut,p);
        triRapide(t,p+1,fin);
    }

}

void triRapide2(Tab t, int debut, int fin)
{
    int p;
    if(debut<fin)
    {
        p=partitionner2(t,debut,fin);
        triRapide2(t,debut,p);
        triRapide2(t,p+1,fin);
    }
}

void affichage(Tab t, int n )
{
    for(int i=0; i<n;i++)
    {
        printf(" %d ", *(t+i));
    }
}
int main()
{
 Tab t={3,17,9,15,2,7,10,9,8,12};
 affichage(t,10);
 printf("\n");
 printf("before call triRapide");
 triRapide(t,0,10);
 printf("TOTO");
 affichage(t,10);
}
