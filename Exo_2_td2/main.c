#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef char Tab[15];
typedef struct { Tab nom;
                Tab prenom;
                int codeFonction;
                float salaire;} employe;

employe saisieEmploye(employe *e)
{
    printf("Veuillez entrer un nom");
    scanf("%s",e->nom);
    printf("Veuillez entre un prenom");
    scanf("%s",e->prenom);
    printf("Entrer un code fonction");
    scanf("%d",&(e->codeFonction));
    printf("Veuillez entrer un salaire");
    scanf("%f",&(e->salaire));
    return *e;
}

void afficheEmploye(employe *e)
{

    printf("le nom de l'employé est :%s\n",e->nom);
    printf("le prenom de l'employé est :%s\n",e->prenom);
    printf("le codefontion de l'employé est :%d\n",e->codeFonction);
    printf("le salaire de l'employé est :%f\n",e->salaire);
}

void modifEmploye(employe *e)
{
    char *new_nom,*new_prenom; int new_codeFonction; float new_salaire;
    printf("Entrer un nom");
    scanf("%s",&new_nom);
    printf("Entrer un prenom");
    scanf("%s",&new_prenom);
    printf("Entrer un code fonction");
    scanf("%d",&new_codeFonction);
    printf("Entrer un salaire");
    scanf("%f",&new_salaire);
    strcpy(e->nom,&new_nom);
    strcpy(e->prenom,&new_prenom);
    e->codeFonction=new_codeFonction;
    e->salaire=new_salaire;
}
int main()
{
    employe *e;
    saisieEmploye(&e);
    afficheEmploye(&e);
    modifEmploye(&e);
    afficheEmploye(&e);
}
