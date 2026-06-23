#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>     // 你原来漏了这个，toupper需要它

typedef struct{
    char code[9];
    int mc;
    char grade[3];
    char su[6];
} module_t;

int readResults(module_t modules[])
{
    FILE *indata;   
    int num,i,j;
    indata = fopen("results.in","r");
    if(indata==NULL)
    {
        printf("Can't open input file\n");
        exit(1);
    }
    fscanf(indata,"%d",&num);
    for(i=0;i<num;i++)
    {
        // 你原来：
        // for(i=1;i<=num;i++)
        //
        // 后面 computeSAP 用的是
        // for(i=0;i<num;i++)
        //
        // 导致：
        // modules[0] 没读
        // modules[num] 被读了却没算
        //
        // 这是整份代码最大的逻辑错误

        fscanf(indata,"%s%d%s%s",modules[i].code,&modules[i].mc, modules[i].grade,modules[i].su);
        for(j=0; modules[i].su[j]!='\0'; j++)
        {
            modules[i].su[j]= toupper(modules[i].su[j]);
        }
    }
    fclose(indata);
    // 你原来没 fclose
    // 一般不影响答案
    // 但属于规范写法
    return num;
}

float gradeToPt(char grade[])
{
    char grades[11][3]={ "A+","A","A-","B+","B","B-","C+","C","D+","D","F"};
    float pts[11]={5.0,5.0,4.5,4.0,3.5,3.0,2.5,2.0,1.5,1.0,0.0};
    int i;
    for(i=0;i<11;i++)
    {
        if(strcmp(grades[i],grade)==0)return pts[i];
    }
}

float computeSAP(module_t modules[],int num)
{
    int i;
    float sum=0.0;
    float deno=0.0;
    for(i=0;i<num;i++)
    {
        if(strcmp(modules[i].su,"TRUE")==0) continue;
        sum += gradeToPt(modules[i].grade)* modules[i].mc;
        deno += modules[i].mc;
    }
    //有除法的时候一定要关注分母会不会是0！！！
    if(deno==0) return 0.0;

    // 你原来直接：
    // return sum/deno;
    //
    // 如果所有模块都S/U
    // 会出现除0

    return sum/deno;
}

int main()
{
    module_t modules[7];
    int num_modules;
    float sap;
    num_modules = readResults(modules);
    sap = computeSAP(modules,num_modules);
    printf("SAP=%.2f\n",sap);
    return 0;
}