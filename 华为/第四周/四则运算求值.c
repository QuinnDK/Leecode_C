#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#define STR_MAX_LEN 128

//对该计算表达式求值，如果在计算过程中遇到除零，返回false。
bool Calculate(char* s,int* result){
    int len = strlen(s);
    if(!s || len == 0)
        return false;
    int *stack = (int*)calloc(len, sizeof(int));
    int top = -1;
    char opreater = '\0';
    int number;
    for(int i = 0; i < len; i++) {
        number = 0;
        if(isdigit(s[i])) {
            while (i < len && isdigit(s[i]))
                number = number * 10 + (s[i++] - '0');
            i--;
            switch (opreater) {
                case '-': number = -number; break;
                case '*': number = stack[top--] * number; break;
                case '/': 
                    if(number){
                        number = stack[top--] / number;
                        break;
                    }else{
                        free(stack);
                        return false;
                    }
                default: break;
            }
            stack[++top] = number;
        } else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
            opreater = s[i];
        }
    }
    while (top != -1)
        *result += stack[top--];
    free(stack);
    return true;
}

int main(){
    char expression[STR_MAX_LEN];
    scanf("%s",expression);
    int result=0;
    bool isOk=Calculate(expression,&result);
    if(isOk){
        printf("%d\n",result);
    }else{
        printf("error\n");
    }
    return 0;
}