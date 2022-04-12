#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<uthash/uthash.h>

struct my_struct{
    char name[10];
    int id;
    UT_hash_handle hh;
};

int main(){
    const char **n,*name[]={"joe","bob","betty",NULL};
    struct my_struct *s,*stemp, *users=NULL;

    int i=0;
    for(n=name;*n!=NULL;n++){
        s=(struct my_struct*) malloc(sizeof(struct my_struct));
        if(s==NULL) exit(-1);
        strcpy(s->name,*n);
        s->id++;
        HASH_ADD_STR(users,name,s);
    }
    HASH_FIND_STR(users,"betty",s);
    if(s) printf("betty's id is %d\n",s->id);

    HASH_ITER(hh,users,s,stemp){
        HASH_DEL(users,s);
        free(s);
    }
    return 0;
}