#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef int Tab[MAX];


void affichage(Tab t, int n)
{
    for(int i=0; i<n;i++)
    {
        printf("%d ",t[i]);
    }
}
void permuter(Tab t, int i, int j)
{
    int temp;
    temp=t[i];
    t[i]=t[j];
    t[j]=temp;
}
void triTableau(Tab t, int n)
{
    int i,j;
   for(i=0;i<n-1;i++)
    {
        for(j=i;j<n;j++)
        {
            if(t[i]<t[j])
            {
                permuter(t,i,j);
            }
        }
    }
}
 void fusion(Tab t1, int n1, Tab t2, int n2) //complexité O(n1+n2)
{
Tab t[n1+n2];
int i, j, k=0;
for(i=0; i <n1+n2; i++ )
if(t1[i]<t2[j]){
t[k]=t1[i];
i++;
}
else {
t[k]=t2[j];
j++;
}
for(i=0 ; i<n1; i++) {t[k]=t1[i]; k++;}
for(j =0; j<n2; j++ ) {t[k]=t2[j]; k++;}
}


int main()
{
    Tab t1={12,5,6,14,3};
    Tab t2={2,8,7,3,4};
    affichage(t1, 5);
    printf("\n");
    affichage(t2,5);
    printf("\n");
    fusion(t1,5,t2,5);
}


//Si tous les éléments de t1 < tous les éléments de t2, j'aurais n2 compairsaon
//si tous les éléments de t1 = t2 : n1+n2 comparaison

