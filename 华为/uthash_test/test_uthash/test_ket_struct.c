#include<stdlib.h>
#include<stdio.h>
#include "uthash/uthash.h"

typedef struct{
    char a;
    int b;
}record_key_t;

typedef struct{
    record_key_t key;
    UT_hash_handle hh;
}record_t;

/*
结构体做key,由于结构体内 存在 字节对齐 填充一些垃圾数据
需要在添加hash 或 查找之前，归零这些填充字节。
*/

int main(int argc,char *argv[]){
    record_t l,*p,*r,*tmp,*records=NULL;

    r=(record_t*) malloc(sizeof(*r));
    memset(r,0,sizeof(*r)); //归零
    r->key.a='a';
    r->key.a=1;
    HASH_ADD(hh,records,key,sizeof(record_key_t),p);
    if(p) printf("found %c %d\n",p->key.a,p->key.b);
    
    memset(&l,0,sizeof(l));
    l.key.a='a';
    l.key.b=1;
    HASH_FIND(hh,records,&l.key,sizeof(record_key_t),p);
    if(p) printf("found %c %d\n",p->key.a,p->key.b);

    HASH_ITER(hh,records,p,tmp){
        HASH_DEL(records,p);
        free(p);
    }
    return 0;
}