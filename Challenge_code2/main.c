#include <stdio.h>
#include <stdlib.h>

typedef char Tab[15];
typedef struct { Tab nom;
                Tab prenom;
                int codeFonction;
                float salaire;}
Employe;


Employe saisieEmploye(Employe *e)
{

    printf("Write nom\n");
    scanf("%s", (e->nom));
    printf("Write prenom\n");
    scanf("%s", (e->prenom));
    printf("Write code fonction \n ");
    scanf("%d", &(e->codeFonction));
    printf("Write salaire\n");
    scanf("%f",&(e->salaire));
    return *e;
    free(e);
}

void afficheEmploye(Employe *e)
{

    printf("le nom de l'employ� est :%s\n",e->nom);
    printf("le prenom de l'employ� est :%s\n",e->prenom);
    printf("le codefontion de l'employ� est :%d\n",e->codeFonction);
    printf("le salaire de l'employ� est :%f\n",e->salaire);
}

int main(int argc, char *argv[])
{
    Employe *e1;
    e1=(Employe*)malloc(1*sizeof(Employe));// Ici on ne viens pas d�clarer l'employe comme �tant un pointeur
    saisieEmploye(&e1);
    afficheEmploye(&e1);
    return 0;
}
