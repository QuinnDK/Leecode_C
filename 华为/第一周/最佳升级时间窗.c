/*
 * Copyright (c) Huawei Technologies Co., Ltd.  All rights reserved.
 * Note: 缺省代码仅供参考，可自行决定使用、修改或删除
 */
#include <stdio.h>
#include "securec.h"

#define ARR_LEN (7 * 24)
void GetBestWindow(int n, int arr[ARR_LEN], int *start, int *end)
{
    // 在此添加你的代码
    *start = -1;
    *end = -1;
    int ends[ARR_LEN] = {0};
    int maxSize = -1;
    int maxIndex = -1;
    // maxSize 表示多大窗口大小,maxIndex 表示最大窗口的起始
    // ends[i]表示以i为首的最大窗口的end的编号
    for(int i=0; i<ARR_LEN; i++){
        unsigned int sum = 0;
        for(int j=0; j<ARR_LEN; j++){
            // 动态结尾
            int searchIndex = i+j<ARR_LEN? i+j:i+j-ARR_LEN;
            sum += arr[searchIndex];
            if(sum<=n){
                ends[i] = searchIndex;
                if(j>maxSize){
                    maxSize = j;
                    maxIndex = i;
                }
            }else{
                break;
            }
            if(j==ARR_LEN-1){
                *start = i;
                *end = searchIndex;
                return ;
            }
        }
    }
    *start = maxIndex;
    if(*start==-1){
        *end = -1;
    }else{
        *end = ends[maxIndex];
    }
}
/* 代码仅供参考，注意避免圈复杂度过大 */
int main(void)
{
    int n;
    if (scanf_s("%u\n", &n) != 1) { return -1; }

    static int arr[ARR_LEN];
    for (int i = 0; i < ARR_LEN; i++) {
        if (scanf_s("%u", &arr[i]) != 1) {
            return -1;
        }
    }

    int start, end;
    GetBestWindow(n, arr, &start, &end);
    (void)printf("%d %d", start, end);
    return 0;
}
