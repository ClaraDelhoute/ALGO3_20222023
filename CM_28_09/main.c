#include <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef float Tab_notes[MAX]; //Définition de mon tableau note qui contient MAX réels
typedef int Tab_coefficient[MAX]; //Définition de mon tableau coefficient qui contient MAX entiers

/*pour p élèves on peut utiliser une structure etudiant
typedef struct{ Tab_notes t; Tab_coefficients coeff} etudiant; 
On peut alors faire un tablau d'etudiant et donc stocké des etudians et leurs notes et coefficients dedans
*/
void saisie_note(Tab_notes note) //procédure saisie des valeurs des notes
{
    int i;
    for(i=0;i<MAX;i++)
    {
        printf("Entrer la %d note",i+1);
        scanf("%f",&note[i]);
        if(*(note+i)>20 || *(note+i)<0)
        {
            printf("Erreur : une note ne peut pas être superieur à 20 ou inférieur à 0");
            break;  //on break pour arrêter le programme
            //TODO eviter de break pour éviter de fermer le programme et de relancer, futur essai de try/catch
        }
    }
}
void saisie_coeff(Tab_coefficient coeff) //saisie de MAX coeff
{
    int i;
    for(i=0;i<MAX;i++)
    {
        printf("Saississez un coefficient");
        scanf("%d",&coeff[i]);
    }
}

void affichage_tableau(Tab_notes note,Tab_coefficient coeff) //affichage de mes deux tableaux
{
    int i, *r; float *p;
    p=note;
    r=coeff;
    for(i=0;i<MAX;i++)
    {
        printf("la %dEme valeur est : %2.2f\n " ,i+1,*(note+i));
        p++;
    }
    printf("\n");
    for(i=0;i<MAX;i++)
     {
         printf("le %deme coefficient est : %d\n",i+1,*(coeff+i));
         r++;
     }
}

float calcul_moyenne(Tab_notes note,Tab_coefficient coeff, float * moyenne) //fonction qui calcule la moyenne des notes en fonction des coefficients
{
    int i;
    float somme=0; int somme_coeff=0;
    float *p=&note[0];
    int *r=&coeff[0];
    for(i=0;i<MAX;i++)
    {
        somme=somme+(*(note+i)*(*(coeff+i)));
        somme_coeff=somme_coeff+ *(coeff+i);

        p++;
        r++;
    }
    *moyenne=somme/somme_coeff;
    return *moyenne;
}
float minimun(Tab_notes note, float *min) //fonction qui retourne le minimun
{
    int i;
    *min=*note;
    for(i=0;i<MAX;i++)
    {
        if(*min > *(note+i))
        {
            *min =*(note+i);
        }
    }
    return *min;
}

float maximun(Tab_notes note, float *max) //fonction qui retourne le maximun
{
    int i;
    *max=*note;
    for(i=0;i<MAX;i++)
    {
        if(*max < *(note+i))
        {
            *max =*(note+i);
        }
    }
    return *max;
}

void modifier_valeur_position_i(Tab_notes note,int *position) //procédure qui remplace une note par une autre note
{

    float nouvelle_valeur;
    if(*position <=0 || *position >10) //on veut pouvoir modifier une note de la PREMIERE note à la DIZIEME note
    {
        printf("On peut modifier de la premiere à la dizieme note");
    }
    else{
    printf("Entrer la nouvelle valeur");
    scanf("%f",&nouvelle_valeur);
    if(nouvelle_valeur<=20 && nouvelle_valeur>=0 ) //une note ne peux pas être supérieur à 20 et inférieur à 0
    {
    *(note+*(position)-1)=nouvelle_valeur;  //Pour modifier la note du t[i-1] car la première note commence à 1 et la dernière à 10
    }
    }
}

void ajout_1 (Tab_notes note) //procédure qui ajoute 1 à la note
{
    int i;
    for(i=0;i<MAX;i++)
    {
        if(*(note+i)< 19)  //Une note ne peut pas aller au delà de 20
        {
            *(note+i)=*(note+i)+1.0;
        }
        else
        {
            *(note+i)=20.00; //si une note est supérieur à 19, on la met à 20
        }
    }
}


int main()
{
    int i;
    float moyenne; float max,min;
    Tab_notes note;
    Tab_notes note_1={20,19.7,19,0,0.1,9,2.5,17.2,12.3,12.4};
    Tab_notes note_2={0.9,0.98,0.78,0.54,0.32,0.65,0.45,0.49,0.85,0.74};
    Tab_coefficient coeff, coeff_1={2,3,2,1,5,2,2,1,1,3};
    saisie_note(note);
    saisie_coeff(coeff);
    affichage_tableau(note,coeff);
    printf("\n la moyenne est : %2.3f\n", calcul_moyenne(note,coeff,&moyenne));
    printf(" le maximun est : %f\n",maximun(note,&max));
    printf("Le minimun est : %f\n",minimun(note,&min));
    ajout_1(note);
    int position;
    printf("Entrer la position de la note que vous voulez modifier");
    scanf("%d",&position);
    modifier_valeur_position_i(note,&position);
    affichage_tableau(note,coeff);
        //Test avec note_1 et coeff_1
    printf("\n la moyenne est : %2.3f\n", calcul_moyenne(note_1,coeff_1,&moyenne)); //Affiche moyenne=10.332
    printf(" le maximun est : %f\n",maximun(note_1,&max)); //maximun = 20
    printf("Le minimun est : %f\n",minimun(note_1,&min)); //min =0
    ajout_1(note_1); /*le 20 reste 20
    le 19.7 passe à 20 et le reste prend 1 point */
    printf("Entrer la position de la note que vous voulez modifier");
    scanf("%d",&position);
    modifier_valeur_position_i(note_1,&position); //modification de la deuxième valeur en 18.5
    printf("les nouvelles notes sont : \n");
    affichage_tableau(note_1,coeff_1); //affichage tableaux

    /*Test avec note_2 et coeff_1
    Vérification du min et max */
    printf("\n la moyenne est : %2.3f\n", calcul_moyenne(note_2,coeff_1,&moyenne)); //Affiche moyenne=0.645
    printf(" le maximun est : %f\n",maximun(note_2,&max)); //maximun = 0.98
    printf("Le minimun est : %f\n",minimun(note_2,&min)); //min =0.32
    ajout_1(note_2); /*Toutes les valeurs prennent 1 point */
    printf("Entrer la position de la note que vous voulez modifier");
    scanf("%d",&position);
    modifier_valeur_position_i(note_2,&position); //modification de la deuxième valeur en 18.5
    printf("Les nouvelles notes sont : \n");
    affichage_tableau(note_2,coeff_1); //affichage tableaux

}
