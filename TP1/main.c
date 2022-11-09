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


int saisieClients(Tab t, int p, int *nbClients)
{
    int i,retour;
    if( p  < MAX-*nbClients)
    {
        printf("toto");
        for(i=0;i<p;i++)
        {
            Client c;
            ajouter(c,t,nbClients);

        }
    }
    else
    {
        retour=0;
    }
    return retour;
}


void modifierNom(Tab t, int nbClients, int i)
{
    for(int j=0; j<nbClients; j++)
    {
        if(t[j].identifiant == i)
        {
            printf("Veuillez entre le nouveau nom \n");
            Chaine nouveau_nom;
            scanf("%s", nouveau_nom);
            strcpy(t[i].nom, nouveau_nom);
        }
    }
}

void afficherClients(Tab t, int nbClients)
{
    int i;
    for(i=0;i<MAX-nbClients;i++)
    {
        printf("L'identifiant %d \n", t[i].identifiant);
        printf("Le nom : %s \n", t[i].nom);
    }
}

int rechercheClient(int idClient, Tab t, int nbClients, int *indiceClient)
{
        int indice, retour;
        int i;
        for(i=0; i<nbClients;i++)
        {
            if(t[i].identifiant == idClient)
            {
                indice= i;
                retour=1;
            }
            else
            {
                retour=0;
            }
        }
        *indiceClient=indice;
        return retour;
}

void rechercheIdMinMax(Tab t, int nbClients, int * indiceIdMin, int * indiceIdMax)
{
    int i;
    int idMin= t[0].identifiant;
    int idMax = t[0].identifiant;
    for(i=1;i<nbClients; i++)
    {

            if( idMin > t[i].identifiant)
            {
                idMin= t[i].identifiant;
            }
            if (idMax < t[i].identifiant)
            {
                idMax = t[i].identifiant;
            }

    }
    *indiceIdMax=idMax;
    *indiceIdMin=idMin;
}
int afficherDoublons(Tab t, int nbClients)
{
    int i,j;
    int numberOfDoublons = 0;
    for(i=0; i<nbClients-1; i++)
    {
        for(j=i; j<nbClients; j++)
        {
            if ( strcmp(t[i].nom, t[j].nom)==0 && t[i].identifiant==t[j].identifiant )
            {
                printf("Id du doublons : %d \n", t[i].identifiant);
                printf("Nom du doublons : %s \n", t[i].nom);
                numberOfDoublons++;

            }
        }
    }
    return numberOfDoublons/2; //car le programme va calculer 2 fois les doublons
}

int ajouterSansDoublons(Client c, Tab t, int * nbClients)
{
    int i;
    int retour;
    t=(Client*)malloc(*nbClients*sizeof(Client));
    for(i=0;i<*nbClients; i++)
    {
        if(t[i].identifiant == c.identifiant && t[i].nom == c.nom)
        {
            ajouter(c,t,nbClients);
            retour=1;
        }
        else
        {
            retour=0;
        }
    }
    ajouter(c,t,nbClients);
    return retour;
}
int enleverClient (int idClient, Tab t, int *nbClients)
{
    int retour;
    int i,j;
    for(i=0; i<*nbClients; i++)
    {
        if(t[i].identifiant== idClient)
        {
            for(j=i;i<*nbClients;j++)
            {


            t[j].identifiant=t[j+1].identifiant;
            strcpy(t[j].nom, t[j+1].nom);
        }
        *nbClients=*nbClients-1;
        retour=1;
        }
        else retour=0;
    }
    return retour;
}

int main()
{
    Client c1;
    int nbClients=0;
    int indiceClient;
    int indiceMin,indiceMax;
    Tab t;
    saisie(&c1); //Test ok
    afficheClient(&c1); //Test ok
    saisieClients(t,3,&nbClients); //Test ok;
    afficherClients(t,MAX-nbClients); //Test ok
    rechercheClient(8,t,nbClients,&indiceClient);
    printf("L'indice du client recherche est : %d \n", indiceClient); //Test ok
    rechercheIdMinMax(t,nbClients,&indiceMin,&indiceMax); //test ok
    printf("L'indice du minimun est %d, l'indice du maximun est %d ", indiceMin, indiceMax); //test ok
    printf(" Nombre de doublons : %d \n ",afficherDoublons(t,nbClients));
    printf("%d \n ",ajouterSansDoublons(c1,t,&nbClients));
    enleverClient(8,t,&nbClients);
    afficherClients(t,nbClients);
    return 0;
}
