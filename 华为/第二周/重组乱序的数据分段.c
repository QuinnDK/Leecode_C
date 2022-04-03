/*
 * Copyright (c) Huawei Technologies Co., Ltd. All rights reserved.
 * Note: 缺省代码仅供参考，可自行决定使用、修改或删除
 */
#include "securec.h"

#define MAX_N 200
#define DATA_BUF_LEN 16
#define OUT_BUF_LEN 512

struct DataSec {
    int type;
    int index;
    int endFlag;
    int len;
    char data[DATA_BUF_LEN];
};

void Recombine(struct DataSec *data, int n, int dstType, char *outBuf, int outBufLen)
{
    int endIndex=-1;
    char resultString[MAX_N][DATA_BUF_LEN];
    int resultStringLen[MAX_N]; //记录目标数据长度
    for(int i=0;i<n;i++){
        if(data[i].type==dstType){
            if(resultStringLen[data[i].index]){
                continue;
            }
            strcpy(resultString[data[i].index],data[i].data);
            resultStringLen[data[i].index]=data[i].len;
            if(data[i].endFlag){
                endIndex=data[i].index;
            }
        }
        //不是目标类型不处理
    }
    if(endIndex==-1){
        outBuf[0]='N';
        outBuf[1]='A';
        outBuf[2]='\0';
        return;
    }
    int count=0;
    for(int i=0;i<=endIndex;i++){
        if(strlen(resultString[i])==resultStringLen[i] && resultStringLen[i]!=0){
            for(int j=0;j<resultStringLen[i];j++){
                outBuf[count++]=resultString[i][j];
            }
        }else{
            outBuf[0]='N';
            outBuf[1]='A';
            outBuf[2]='\0';
            return;
        }
    }
    outBuf[count]='\0';
}

/* 代码仅供参考，注意避免圈复杂度过大 */
int main(void)
{
    int n;
    if (scanf_s("%d", &n) != 1) { return -1; }

    static struct DataSec data[MAX_N];

    int i;
    for (i = 0; i < n; i++) {
        int ret = scanf_s("%d %d %d %d %s",
                          &data[i].type,
                          &data[i].index,
                          &data[i].endFlag,
                          &data[i].len,
                          data[i].data, sizeof(data[i].data));
        if (ret != 5) { return -1; }
    }

    int dstType;
    if (scanf_s("%d", &dstType) != 1) { return -1; }

    static char outBuf[OUT_BUF_LEN];
    Recombine(data, n, dstType, outBuf, sizeof(outBuf));
    (void)printf("%s", outBuf);
    return 0;
}

