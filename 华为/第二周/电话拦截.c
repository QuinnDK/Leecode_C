/*
 * Copyright (c) Huawei Technologies Co., Ltd.  All rights reserved.
 * Note: 缺省代码仅供参考，可自行决定使用、修改或删除
 */
#include <stdio.h>
#include "securec.h"

#define MAXN 3000
#define PHONE_NUM_BUF_LEN 16
#define OUT_BUF_LEN (3000 * 16)

typedef struct {
    char op;
    char phoneNum[PHONE_NUM_BUF_LEN];
} PhoneRecord;

int countWrite=0;
int countNum=0;
char numNum[MAXN+5][PHONE_NUM_BUF_LEN];
int numIn[MAXN+5] = {0};
int numReject[MAXN+5] = {0};
    char whiteNums[MAXN+5][PHONE_NUM_BUF_LEN];
/* 待实现函数，在此函数中填入答题代码。结果输出到 outBuf/outBufLen 中 */
void GetPhoneRecord(const PhoneRecord *records, int num, char *outBuf, int outBufLen)
{

    for(int i=0;i<num;i++){
        if(records[i].op=='C'){
            //判断是接还是挂
            //1,查询白名单
            int callIn=0;
            for(int j=0;j<countWrite;j++){
                for(int k=0;k<strlen(records[i].phoneNum);k++){
                    if(whiteNums[j][k]=='*'){
                        callIn=1;
                        break;
                    }else if(whiteNums[j][k]==(records[i].phoneNum)[k]){
                        if(k==strlen(records[i].phoneNum)-1){
                            callIn=1;
                            break;  
                        }
                    }else{
                        break;
                    }
                }
                if(callIn){
                    break;
                }
            }
            //记录
            for(int j=0;j<=countNum;j++){
                if(j==countNum){
                    strcpy(numNum[countNum],records[i].phoneNum);
                    if(callIn){
                        numIn[countNum]++;
                    }else{
                        numReject[countNum]++;
                    }
                    countNum++;
                    break;
                }
                if(strcmp(records[i].phoneNum,numNum[j])==0){
                    if(callIn){
                        numIn[j]++;
                    }else{
                        numReject[j]++;
                    }
                    break;
                }
            }
        }else{
            //添加白名单
            strcpy(whiteNums[countWrite],records[i].phoneNum);
            countWrite++;
        }
    }
    int count=0;
    for(int i=0;i<countNum;i++){
        for(int j=0;j<strlen(numNum[i]);j++){
            outBuf[count++]=numNum[i][j];
        }
        outBuf[count++]=' ';
        // 写接入次数
        outBuf[count++] = (char)((int)'0'+numIn[i]);
        outBuf[count++] = ' ';
        // 写拒绝次数
        outBuf[count++] = (char)((int)'0'+numReject[i]);
        outBuf[count++] = '\n';
        
    }
    // 结尾
    outBuf[count] = '\0';
}

int main(void)
{
    int num;
    if (scanf_s("%d\n", &num) != 1) { return -1; }

    PhoneRecord records[MAXN];
    for (int i = 0; i < num; i++) {
        if (scanf_s("%c %s\n", &records[i].op, sizeof(char), records[i].phoneNum, PHONE_NUM_BUF_LEN) != 2) {
            return -1;
        }
    }

    static char outBuf[OUT_BUF_LEN];
    GetPhoneRecord(records, num, outBuf, sizeof(outBuf));
    (void)printf("%s", outBuf);

    return 0;
}
