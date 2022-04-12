#include<stdio.h>
#include<strings.h>
#include<stdbool.h>

#define LEN 65535
char Alphabet[27]={0};
void MakeAlphabet(char* Alphabet){
    Alphabet['a'-'a']=1;
    Alphabet['e'-'a']=1;
    Alphabet['i'-'a']=1;
    Alphabet['o'-'a']=1;
    Alphabet['u'-'a']=1;
}

int findYY(char x){
    int res=0;
    
    if(x>='a' && Alphabet[x-'a']==1){
        res=1;
    }else if(Alphabet[x-'A']==1){
        res=1;
    }
    return res;
}

void  CountLen(const char* strings,int stringLen,const int flaw,int *Maxlen){
    int countFlaw=0; //计算瑕疵度；
    int left=0;
    int right=0;
    int count=0;
    for(right=0;right<stringLen;right++){
        bool isVowel=findYY(strings[right])==1 ? true:false;
        if(!isVowel){
            count++;
        }
        if(!isVowel || count<flaw){
            continue;
        }
        if(count==flaw && findYY(strings[left])){
            *Maxlen=(right-left+1)>*Maxlen ? (right-left+1):*Maxlen;
            continue;
        }
        while(count>flaw || findYY(strings[left])!=1){
            left++;
            if(findYY(strings[left-1])!=1){
                count--;
            }
            if(left>right){
                left=right;
                break;
            }
        }
        if(count==flaw && findYY(strings[left])){
            *Maxlen=(right-left+1)>*Maxlen ? (right-left+1):*Maxlen;
        }
    }

}
int main(){
    int flaw=-1;
    int num=0;
    char strings[LEN]={0};
    scanf("%d",&flaw);
    scanf("%s",strings);
    int stringLen=strlen(strings);
    int *Maxlen=&num;
    MakeAlphabet(Alphabet);
    CountLen(strings,stringLen,flaw,Maxlen);
    printf("%d",*Maxlen);
}