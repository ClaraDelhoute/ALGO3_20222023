#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

typedef char Chaine[15];

typedef struct {
                int identifiant;
                Chaine nom;
                } Client;

typedef Client Tab[MAX]; // définition de la structure Client et du tableau de Client

void saisie(Client *c) //saisie d'un client
{
    printf("Veuillez saisir un identifiant pour le client\n");
    scanf("%d",&(c->identifiant));
    printf("Veuillez saisir le nom du client\n");
    scanf("%s",c->nom);
}

void afficheClient(Client *c) //affichage d'un client
{
    printf("L'identifiant : %d\n " ,c->identifiant );
    printf("Le nom : %s\n", c->nom);
}

int ajouter(Client c, Tab t, int *nbClients)
{
    int ret;
    if( t != NULL )
    {
        saisie(&c);
        t[*nbClients].identifiant=c.identifiant;
        strcpy(t[*nbClients].nom,c.nom);
        ret=1;
        *nbClients= *nbClients+1;
    }
    else
    {
        ret=0;
    }
    return ret;
}
