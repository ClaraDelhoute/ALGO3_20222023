#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
                int id;
                char nom[15];
                char tel[10];} Client;

typedef Client Tab[50];

void permute(Tab t,int i, int j)
{
    Client  temp=t[i];
    t[i]=t[j];
    t[j]=temp;
}
void saisieClient(Client * c)
{
    printf("Entrer l'id du client\n");
    scanf("%d", &c->id);
    printf("Entrer le nom du client \n");
    scanf("%s",c->nom);
    printf("Entrer le tel du client \n");
    scanf("%s",c->tel);
}

void ajouteClientFichier(char  *nomFichier)
{
    Client c;
    FILE *f;
    f=fopen(nomFichier, "a");
    if (!f) printf("Erreur à l'ouverture du fichier %s\n",nomFichier);
    else
    {

    saisieClient(&c);
    fprintf(f," %d %s %s ",c.id,c.nom, c.tel);
    fclose(f);
    }
}
 void afficheClientsFichier(char * nomFichier)
 {
     int fin;
     FILE *f=fopen(nomFichier,"r");
     Client c;
     while(!feof(f))
     {
         fin=fscanf(f," %d %s %s ", &c.id,c.nom,c.tel);
         if(fin != EOF)
         {
             printf(" %d %s %s ", c.id, c.nom, c.tel);
         }
     }
     fclose(f);
 }

 int nombreClientsFichier(char * nomFichier)
 {
     int compteur=0;
     int fin;
     FILE *f = fopen(nomFichier,"r");
     Client c;
     while(!feof(f))
     {
         fin=fscanf(f," %d %s %s ", &c.id,c.nom,c.tel);
         if(fin !=EOF )
         {
             compteur++;
         }
     }
     return compteur;
 }

void ajouteClientFichier_Bis(char * nomFichier)
{
    Client c,c1;
    int trouve;
    FILE *f=fopen(nomFichier,"a+");
    saisieClient(&c1);
    while(!feof(f))
    {
        fscanf(f," %d %s %s ",&c.id,c.nom,c.tel);
        if(c.id == c1.id || strcmp(c.nom,c1.nom)==0 || strcmp(c.tel,c1.tel)==0)
        {
            trouve=0;
        }
        else
        {
            trouve=1;
        }
    }
    if(trouve==1)
    {
        fprintf(f," %d %s %s ", c1.id, c1.nom, c1.tel);
    }
    else
    {
        printf("Le client existe deja\n");
    }
    fclose(f);
}

void triClientsFichier(char *nomFichier)
{
    Tab t;
    Client c;
    FILE *f=fopen(nomFichier, "r+");
    int i,j;
    int nb=nombreClientsFichier(nomFichier);
    while(!feof(f))
    {
        for(i=0;i<nb;i++)
        {
            fscanf(f, " %d %s %s ",&c.id, c.nom, c.tel);
           t[i].id=c.id;
            strcpy(t[i].nom, c.nom );
            strcpy(t[i].tel, c.tel);
        }
    }
    for(i=0; i<nb-1;i++)
    {
        for(j=i;j<nb;j++)
        {
            if(t[i].nom > t[j].nom)
            {
                permute(t,i,j);
            }
        }
    }
    fclose(f);
        fopen(nomFichier,"w+");
    for(i=0;i<nb;i++)
    {
      fprintf(f," %d %s %s " , t[i].id,t[i].nom, t[i].tel);
    }
    fclose(f);

}

void appartientClientFichier(char *nomFichier, char *nom)
{
    FILE *f=fopen(nomFichier,"r");
    Client c;
    int trouve;
    while(!feof(f))
    {
        fscanf(f, "%d %s %s ", &c.id, c.nom, c.tel);
        if(strcmp(c.nom, nom)== 1)
        {
            trouve=1;
        }
        else trouve=0;

    }
    if(trouve ==1)
    {
        printf("Le client appartient au fichier \n");
    }
    else printf("Client non repertorie\n ");
}
int main()
{
    char *nomFichier="C:/Users/clara/OneDrive/Bureau/essai.txt";
   //ajouteClientFichier(nomFichier); //ok
   afficheClientsFichier(nomFichier); //Test ok
   printf("\n");
    printf("%d",nombreClientsFichier(nomFichier)); //Test ok
    printf("\n");
    ajouteClientFichier_Bis(nomFichier); //Test ok
    triClientsFichier(nomFichier);
    printf("\n");
    afficheClientsFichier(nomFichier);
    printf("\n");
    appartientClientFichier(nomFichier,"christian"); //Test ok
   return 0;
}
