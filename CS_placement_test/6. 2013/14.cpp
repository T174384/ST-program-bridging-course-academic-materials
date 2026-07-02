#include<stdio.h>
#include<stdlib.h>
#define MAX 10

typedef struct{
    int rows,cols;
}dim_t;

typedef struct{
    dim_t dim;
    int data[MAX][MAX];
}grid_t;

void readFile(grid_t *x, grid_t *y){
    FILE *indata;
    int i,j;
    indata=fopen("motif.in","r");
    if(indata==NULL){
        printf("can't open");
        exit(1);
    }
    fscanf(indata,"%d%d",&x->dim.rows,&x->dim.cols);
    fscanf(indata,"%d%d",&y->dim.rows,&y->dim.cols);
    for(i=0;i<y->dim.rows;i++){
        for(j=0;j<y->dim.cols;j++){
            fscanf(indata,"%d",&y->data[i][j]);
        }
    }
    fclose(indata);//一定要记住写这个东西
}

void fillPlot(grid_t *x, grid_t *y){
    int i,j;
    int mr=y->dim.rows;
    int mc=y->dim.cols;
    for(i=0;i<x->dim.rows;i++){
        for(j=0;j<x->dim.cols;j++){
            x->data[i][j]=y->data[i%mr][j%mc];
        }
    }
}

void printGrid(grid_t *x){
    int i,j;
    for(i=0;i<x->dim.rows;i++){
        for(j=0;j<x->dim.cols;j++){
            if(j>0) printf(" ");
            printf("%d",x->data[i][j]);
        }
        printf("\n");
    }
}

int main(){
    grid_t x, y;
    readFile(&x,&y);
    fillPlot(&x,&y);
    printGrid(&x);
    return 0;
}