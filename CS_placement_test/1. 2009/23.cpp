#include<stdio.h>
#include<stdlib.h>
#define seed 37
typedef struct{
    int rank;
    int suit;
} card;
card a[53];
void shuff(card a[])
{
    int i;
    for(i=1;i<52;i++)
    {
        // int num=rand()%(52-i)+i+1; 不正确，因为52-52会发生未定义行为
        int num=rand()%(53-i)+i;
        card temp=a[i];
        a[i]=a[num];
        a[num]=temp;
    }
}
int main()
{
    srand(seed);
    int i;
    for(i=1;i<=52;i++)
    {
        scanf("%d%d",&a[i].rank,&a[i].suit);
    }
    shuff(a);
    for(i=1;i<=52;i++)
    {
        printf("%d %d\n",a[i].rank,a[i].suit);
    }
    return 0;
}