#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "uthash/uthash.h"

struct my_struct {
    int id;
    char name[21];
    UT_hash_handle hh;
};

struct my_struct *users=NULL;

//增加用户到hash表中
void add_user(int user_id,const char* name){
    struct my_struct *s;
    HASH_FIND_INT(users,&user_id,s);
    if(s==NULL){
        s=(struct my_struct*)malloc(sizeof *s);
        s->id=user_id;
        HASH_ADD_INT(users,id,s);
    }
    strcpy(s->name,name);
} 
//根据id查找用户
struct my_struct* find_user(int user_id){
    struct my_struct* s;
    HASH_FIND_INT(users,&user_id,s);
    return s;
}
//根据删除用户
void delete_user(struct my_struct* user){
    HASH_DEL(users,user);
    free(user);
}
//删除全部用户
void delete_all(){
    struct my_struct *current_user;
    struct my_struct *tmp;
    HASH_ITER(hh,users,current_user,tmp){
        HASH_DEL(users,current_user);
        free(current_user);
    }
}
//打印
void print_users(){
    struct my_struct *s;
    for(s=users;s!=NULL;s=(struct my_struct*)(s->hh.next)){
        printf("user id %d: name %s\n",s->id,s->name);
    }
}
//根据名字排序
int by_name(const struct my_struct* a,const struct my_struct* b){
    return strcmp(a->name,b->name);
}
//根据ID排序
int by_id(const struct my_struct* a,const struct my_struct* b){
    return  b->id - a->id;
}


const char *getl(const char *prompt){
    static char buf[21];
    char* p;
    printf("%s?",prompt); fflush(stdout);
    p=fgets(buf,sizeof(buf),stdin);
    if(p==NULL || (p=strchr(buf,'\n'))==NULL){
        puts("Invalid input");
        exit(EXIT_FAILURE);
    }
    *p='\0';
    return buf;
}

int main(){
    int id=1;
    int running=1;
    struct my_struct *s;
    int temp;

    while(running){
        printf("1. add user\n");
        printf("2. add or rename user by id\n");
        printf("3. find user\n");
        printf("4. delete user\n");
        printf("5. delete all users\n");
        printf("6. sort items by name\n");
        printf("7. sort items by id\n");
        printf("8. print users\n");
        printf("9. count users\n");
        printf("10. exit\n");

        switch (atoi(getl("Command")))
        {
            case 1:
                add_user(id++,getl("Name (20 chars max)"));
                break;
            case 2:
                temp=atoi(getl("Id"));
                add_user(temp,getl("Name (20 chars max)"));
                break;
            case 3:
                s=find_user(atoi(getl("Id to find")));
                printf("user: %s\n",s? s->name:"not found");
                break;
            case 4:
                s=find_user(atoi(getl("Id to delete")));
                if(s)
                    delete_user(s);
                else
                    puts("not found");
                break;
            case 5:
                delete_all();
                break;
            case 6:
                HASH_SORT(users,by_name);
                break;
            case 7:
                HASH_SORT(users,by_id);
                break;
            case 8:
                print_users();
                break;
            case 9:
                printf("%d users\n",HASH_COUNT(users));
                break;
            case 10:
                running=0;
                break;
        }
    }
    delete_all();
    return 0;
}