#include <stdio.h>
#include <stdlib.h>
typedef char Tab[15];
typedef struct { Tab nom;
                Tab prenom;
                int codeFonction;
                float salaire;} employe;

typedef employe TabEmploye[100];
employe saisieEmploye_simple(employe *e)
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
void saisieEmploye(TabEmploye *tabe, int *n)
{
    int i;
    tabe= (employe*)malloc(*n*sizeof(employe));
    for(i=0;i<*n;i++)
    {
        saisieEmploye_simple(&(*tabe[i]));
    }
    free(tabe);

}

void affichageEmploye(TabEmploye *tabe,int *n )
{
    int i;
    tabe= (employe*)malloc(*n*sizeof(employe));
    for(i=0;i<*n;i++)
    {
        printf("le nom est :%s \n", tabe[i]->nom);
        printf("le prenom est :%s \n" , tabe[i]->prenom);
        printf("le code fonction est %d \n", tabe[i]->codeFonction);
        printf("le salaire est de %f\n ",tabe[i]->salaire);

    }
    free(tabe);
}

void recherche_employe(TabEmploye *tabe, char *nom,char * prenom)
{
    int i;
    for(i=0;i<*tabe;i++)
    {


        if(tabe[i]->nom==*nom && tabe[i]->prenom==*prenom)
        {
            printf("L'employé a été trouvé");
        }
    }
}
int main()
{
    TabEmploye *tabe;
    int n;
    char nom="Robert", prenom="Georges";
    printf("Combien d'employés voulez vous insérer ? ");
    scanf("%d",&n);
    saisieEmploye(&tabe,&n);
    affichageEmploye(&tabe,&n);
    recherche_employe(&tabe,&nom,&prenom);
}
