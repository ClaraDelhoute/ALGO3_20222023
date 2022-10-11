#include <stdio.h>
#include <stdlib.h>
/* Exercice 1 TD2 */

typedef struct { char nom[15];
                char prenom[15];
                int codeFonction;
                float salaire;}employe;
int main()
{
    employe e;
    employe *pe;
    pe=&e;
    printf("Veuillez entrer un nom");
    scanf("%s",pe->nom);
    printf("Veuillez entre un prenom");
    scanf("%s",pe->prenom);
    printf("Entrer un code fonction");
    scanf("%d",&(pe->codeFonction));
    printf("Veuillez entrer un salaire");
    scanf("%f",&(pe->salaire));
    printf("L'employé est %s %s avec un code de fonction %d et un salaire de %f",((*pe).nom),((*pe).prenom),((*pe).codeFonction),((*pe).salaire));
}
