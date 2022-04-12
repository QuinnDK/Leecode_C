#include<stdio.h>
#include"uthash/utarray.h"

int main(){
    UT_array *nums; //动态数组
    int i,*p;

    utarray_new(nums,&ut_int_icd);
    for(int i=0;i<10;i++) utarray_push_back(nums,&i);

    for(p=(int*) utarray_front(nums);p!=NULL;p=(int*) utarray_next(nums,p)){
        printf("%d\n",*p);
    }
    utarray_free(nums);
    return 0;
}