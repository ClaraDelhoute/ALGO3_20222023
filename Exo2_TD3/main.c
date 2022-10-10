#include <stdio.h>
#include <stdlib.h>

 int suite (int n)
{
    if(n == 0)
    {
        return 1;
    }
    else
    {
        return 2+suite(n-1);
    }
}

int recursive_puissance(int a, int n) // question 2)a et b
{
    if(a==1 || n==0)
    {
        return 1;
    }
    else {
        if(a==0)
        {
            return 0;
        }
        else
        {
            if(n==1)
        {
            return a;
        }
        else
        {
            return a*recursive_puissance(a,n-1);
        }
    }
}
}


int fonction_recursive(int a,int n) // Question c
{
    if(a == 0)
    {
        return 0;
    }
    else
    {
        if(a==1 || n==0)
        {
            return 1;
        }
        else
        {
            if( n%2 == 0)
            {
                return fonction_recursive(a,n/2)*fonction_recursive(a,n/2);
            }
            else
            {
                if(n%2 != 0 )
                {
                    return a*recursive_puissance(a,n-1);
                }
            }
        }
    }
}





int main()
{
    printf("%d\n",suite(5)); //Test
    printf("%d\n",recursive_puissance(2,3)); //Test
    printf("%d\n",fonction_recursive(6,2)); //Test
    printf("%d\n",fonction_recursive(7,2)); //Test ok
    printf("%d\n",fonction_recursive(6,3)); //Test ok
    printf("%d\n",fonction_recursive(2,7)); //Test ok


}
