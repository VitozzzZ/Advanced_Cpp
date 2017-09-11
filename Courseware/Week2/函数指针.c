//调用qsort函数，将一个unsigned int数组按个位数从小到大顺序排列
#include <stdio.h>
#include <stdlib.h>
int MyCompare(const void * elem1,const void * elem2)
{
    unsigned int * p1,* p2;
    p1=(unsigned int *)elem1;
    p2=(unsigned int *)elem2;
    return (*p1%10)-(*p2%10);
}
#define NUM 5
int main()
{
    unsigned int an[NUM]={8,123,11,10,4};
    qsort(an,NUM,sizeof(unsigned int),MyCompare);
    //qsort(void *base，int num,unsigned int width,int(*pfcompare)（const void*，const void*)
    for(int i=0;i<NUM;i++)
        printf("%d",an[i]);
    return 0;
}
