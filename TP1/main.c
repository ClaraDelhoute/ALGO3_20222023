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

