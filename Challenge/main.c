#include <stdio.h>
#include <stdlib.h>
/* |=== Build: Debug in Challenge (compiler: GNU GCC Compiler) ===|
C:\Users\Delhoute\Desktop\Algo3\Challenge\main.c||In function 'main':|
C:\Users\Delhoute\Desktop\Algo3\Challenge\main.c|39|warning: passing argument 1 of 'saisieEmploye' from incompatible pointer type [-Wincompatible-pointer-types]|
C:\Users\Delhoute\Desktop\Algo3\Challenge\main.c|13|note: expected 'Employe *' {aka 'struct <anonymous> *'} but argument is of type 'Employe **' {aka 'struct <anonymous> **'}|
C:\Users\Delhoute\Desktop\Algo3\Challenge\main.c|40|warning: passing argument 1 of 'afficheEmploye' from incompatible pointer type [-Wincompatible-pointer-types]|
C:\Users\Delhoute\Desktop\Algo3\Challenge\main.c|27|note: expected 'Employe *' {aka 'struct <anonymous> *'} but argument is of type 'Employe **' {aka 'struct <anonymous> **'}|
||=== Build finished: 0 error(s), 2 warning(s) (0 minute(s), 5 second(s)) ===|
*/
/* La fonction retourne un Employe e et non un pointeur *e, lorsqu'on veux renvoyez un pointeur vers la mémoire alloué dynamiquement, on doit toujours affecter
ce pointeur à une variable afin de pouvoir utiliser free pour pouvoir utiliser la mémoire alloué*/
// Modification du code de Challenge1
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
}

void afficheEmploye(Employe *e)
{

    printf("le nom de l'employé est :%s\n",e->nom);
    printf("le prenom de l'employé est :%s\n",e->prenom);
    printf("le codefontion de l'employé est :%d\n",e->codeFonction);
    printf("le salaire de l'employé est :%f\n",e->salaire);
}

int main()
{
    Employe *e1;  // Ici on ne viens pas déclarer l'employe comme étant un pointeur
    saisieEmploye(&e1);
    afficheEmploye(&e1);
    return 0;
}

