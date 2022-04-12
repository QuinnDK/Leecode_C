/*
 * Copyright (c) Huawei Technologies Co., Ltd.  All rights reserved.
 * Note: 缺省代码仅供参考，可自行决定使用、修改或删除
 */
#include "securec.h"
#include <stdbool.h>

static int* pool; // 存者数据的尾部下一个的编号
#define POOL_SIZE 105
// 在此添加你的代码
void MemPoolInit(void)
{
    pool=(int*) malloc(sizeof(int)* POOL_SIZE);
    for(int i=0;i<POOL_SIZE;i++){
        pool[i]=i;
    }
}

// 在此添加你的代码
void MemPoolDeinit(void)
{
    free(pool);
}

/* 返回分配的内存首地址，失败返回 -1，框架会自动输出"error" */
int MemPoolRequest(int memSize)
{
    // 在此添加你的代码
    int count=0;
    int start=0;
    for(int i=0;i<100;i++){
        if(pool[i]==i){
            count++;
            if(count==memSize){
                pool[start]=i+1;
                return start;
            }
        }else{
            count=0;
            start=pool[i];
            i=pool[i]-1;
        }
    }
    return -1;
}

/* 成功返回 true；失败返回 false，框架会自动输出 "error" */
bool MemPoolRelease(int startAddr)
{
    // 在此添加你的代码
    if(pool[startAddr]==startAddr){
        return false;
    }else{
        pool[startAddr]=startAddr;
        return true;
    }
    return true;
}

/* 用例足够使用 */
#define BUF_LEN 64
#define OUT_BUF_LEN 64

/* 代码仅供参考，注意避免圈复杂度过大 */
int main(void)
{
    MemPoolInit();

    int n;
    if (scanf_s("%d\n", &n) != 1)   { return -1; }

    static char buf[BUF_LEN];
    int i;
    for (i = 0; i < n; i++) {
        if (NULL == gets_s(buf, sizeof(buf)))   { return -1; }
        int info = atoi(buf + 8);
        int ret;
        if (buf[2] == 'Q') { // REQUEST
            int ret = MemPoolRequest(info);
            if (ret != -1) { 
                (void)printf("%d\n", ret); 
            } else { (void)printf("error\n"); }
        } else { // RELEASE
            bool ret = MemPoolRelease(info);
            if (ret == false) { (void)printf("error\n"); }
        }
    }

    MemPoolDeinit();
    return 0;
}
