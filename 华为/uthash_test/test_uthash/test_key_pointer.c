#include<stdio.h>
#include<stdlib.h>
#include"uthash/uthash.h"

typedef struct{
    void* key;
    int i;
    UT_hash_handle hh;
}my_struct;

my_struct* hash=NULL;
char* someaddr=NULL;

int main(){
    my_struct *d;
    my_struct *e=(my_struct*) malloc(sizeof(my_struct));
    if(!e) return -1;
    e->key=(void*)someaddr;
    e->i=1;
    HASH_ADD_PTR(hash,key,e);

    HASH_FIND_PTR(hash,&someaddr,d); //HASH_FIND_XXX 如果key是值，则传地址。如果key为指针，则传指针的指针
    if(d) printf("found\n");

    HASH_DEL(hash,e);
    free(e);
    return 0;
}
