#include <stdio.h>
int main()
{
    char*str=NULL;
    if ((str = malloc(0)) == NULL)
    {
        printf("get a null pointer!\n");
    }
    else
    {
        printf("get a valid pointer!\n");
    }
    return 0;
}

