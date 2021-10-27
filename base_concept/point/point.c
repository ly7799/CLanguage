#include <stdio.h>
#include <stdlib.h>
void get_memory(char *p)
{
    p=(char *)malloc(200);
    strcpy(p,"helloworld");
}
int main(int argc, char *argv[])
{
    char*str=NULL;
    get_memory(str);
    printf("%s/n",str);
    free(str);
    return 0;
}
