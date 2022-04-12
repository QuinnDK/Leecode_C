#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char str[105];
    gets(str);
    int index=0;
    int x=0,y=0;
    char dir[5]="NESW";

    for(int i=0;i<strlen(str);i++){
        if(str[i]=='R'){
            index+=1;
            if(index>3) index=0;
        }else if(str[i]=='L'){
            index-=1;
            if(index<0) index=3;
        }
        if(str[i]=='G'){
            if(index==0) y++;
            else if(index==1) x++;
            else if(index==2) y--;
            else if(index==3) x--;
        }
    }
    printf("(%d,%d)",x,y);
}