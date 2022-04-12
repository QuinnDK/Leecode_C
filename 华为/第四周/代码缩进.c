#include<stdio.h>
#include<limits.h>
#define MAX_LEN 1000000

// int GetMinStep(const int* steps,int n){
//     //遍历数组记录step[i]=0之间的最大值
//     int result=0;
//     int max=INT_MIN;
//     for(int i=0;i<n;i++){
//         if(max<steps[i]){
//             max=steps[i];
//         }
//         if(steps[i]==0){
//             result+=max;
//             max=INT_MIN;
//         }
//     }
//     if(max!=INT_MIN){
//         result+=max;
//     }
//     return result;
// }
int GetMinStep(const int* steps,int n){
    int result=0;
    

    return result;
}

int main(){
    int n;
    scanf("%d",&n);
    int steps[MAX_LEN];
    for(int i=0;i<n;i++){
        scanf("%d",&steps[i]);
    }
    int result=GetMinStep(steps,n);
    printf("%d\n",result);
    return 0;

}