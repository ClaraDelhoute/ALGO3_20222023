#include <stdio.h>
#include <stdlib.h>


int longueur(char *c, int *l){
	char *p;
	p = c;
	printf("inside %s",c);
	while(*p != '\0'){
		printf("%c \n", *p);
		*l = *l + 1;
		p++;
		}
		return *l;

}

int longueur_recursive(char *c)
{   int l=0;
    if(*c == '\0')
    {
        return 1;
    }
    else
    {
        return 1+longueur(c,&l);
    }
}

void inverse(char *c)
{
    int i,j=0;
    int l=0;
    char *inverse;
    char *p;
    char *r;
    p=&c[0];
    r=&inverse[0];
    l=longueur(c,&l);
    for(i=l;i>0;i++)
    {
        *(inverse+j)=*(c+i);
        j++;
        p++;
        r++;
    }
    printf("%s",inverse);
}
int main()
{
    int l = 0;
	char * test  = "Test";
	printf("%s",test);
	longueur(test, &l);
	printf("%d\n",l);
	printf("%d",longueur_recursive(test));
	longueur("toto",&l);

	inverse("Toto");
}
