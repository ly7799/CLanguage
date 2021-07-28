#include<stdio.h>
#include<sys/time.h>

int main(int argc,char*argv[])
{
    struct timeval start,end;
    gettimeofday (&start,NULL);/*测试起始时间*/
    double timeuse;
    register double sum;
    register int j,k;
    for (j = 0; j< 100000000; j++)
        for(k = 0; k < 10; k++)
            sum=sum+1.0;
    gettimeofday (&end,NULL); /*测试终止时间*/
    timeuse=1000000*(end.tv_sec - start.tv_sec)+end.tv_usec - start.tv_usec;
    timeuse/=1000000;
    printf("运行时间为：%f 秒\n",timeuse);
    return 0;
}
