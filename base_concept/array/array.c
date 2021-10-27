#include <stdio.h>

int port[4][8]={
    /*5*/{3,6,5,8,2,4,1,7},
    /*4*/{6,8,5,7,1,2,3,4},
    /*6*/{5,4,3,2,8,6,7,1},
    /*7*/{1,2}
};
void show_port()
{
    int i,j;
    int count=0;
    for (i=0;i<3;i++)
    {
        for(j=0;j<8;j++)
        {
            printf("slot:%d port:%d <---> swport:%d\n",i+4,port[i][j],count);
            count++;
        }
    }
    printf("slot:%d port:%d <---> swport:%d\n",i+4,port[i][0],count);
    printf("slot:%d port:%d <---> swport:%d\n",i+4,port[i][1],count+4);
}
int main()
{
    show_port();
    return 0;
}
