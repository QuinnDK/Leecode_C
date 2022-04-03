/*
 * Copyright (c) Huawei Technologies Co., Ltd.  All rights reserved.
 * Note: 缺省代码仅供参考，可自行决定使用、修改或删除 */
#include <stdio.h>
#include "securec.h"

int GetNormalDeviceNum(int start, int end)      
{                     
   // 添加你的代码
   int ans=end-start+1;
   for(int i=start;i<=end;i++){
       int n=i;
       while(n){
           if(n%10==4 || n%100==18){
               --ans;
               break;
           }
           n/=10;
       }
   }
   return ans;          
}                     
int main(void) 
{ 
    int start = 0;  
    if (scanf_s("%d", &start) != 1) { return -1; }   
    int end = 0;  
    if (scanf_s("%d", &end) != 1) { return -1; }   
    int result = GetNormalDeviceNum(start, end);
    (void)printf("%d", result); 
    return 0;           
}  
