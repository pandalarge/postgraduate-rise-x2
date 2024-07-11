//线性表-动态分配
#include <stdio.h>
#include "stdlib.h"
#define InitSize 10
typedef struct {
    int *data;
    int MaxSize;
    int length;
}SeqList;
//初始化，使用malloc函数分配连续的空间（10个int型）
void InitList(SeqList* L){
    L->data= (int*)malloc(sizeof(int)*InitSize);
    L->length=0;
    L->MaxSize=InitSize;
}
//实现动态分配-扩容（将原来数据保存到p，然后重新分配地址给L，
// 将P的数据迁移到L，最后释放p）
void IncreaseSize(SeqList* L,int len){
    int *p=L->data;
    L->data=(int *) malloc(sizeof(int)*(L->MaxSize+len));
    for (int i = 0; i < L->length; i++) {
        L->data[i]=p[i];
    }
    L->MaxSize=L->MaxSize+len;
    free(p);
}
int main() {
    int size=0;
    SeqList L;
    InitList(&L);
    L.data[0]=5;
    L.data[1]=10;
    L.data[2]=10;
    printf("%d",sizeof (&L));
    return 0;
}
