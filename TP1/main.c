#include <stdio.h>
#include <stdlib.h>
#define MAX 100

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
    t=(Client*) malloc(*nbClients*sizeof(Client));
    if( t != NULL )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int saisieClients(Tab t, int p, int *nbClients)
{
    int i;
    t=(Client*)calloc(*nbClients,sizeof(Client));
    if( t != NULL )
    for(i=0;i<p;i++)
    {
        saisie(&(t[i]));
        return 1;
    }
    else
    {
        return 0;
    }
    free(t);
}

void afficherClients(Tab t, int nbClients)
{
    int i;
    for(i=0;i<nbClients;i++)
        t=(Client*)malloc((nbClients)*sizeof(Client));
    {
        afficheClient(&t[i]);
    }
    free(t);
}

int main()
{
    Client c1;
    int nbClients=MAX;
    Tab t;
    saisie(&c1); //Test ok
    afficheClient(&c1); //Test ok
    saisieClients(t,12,MAX);
}
