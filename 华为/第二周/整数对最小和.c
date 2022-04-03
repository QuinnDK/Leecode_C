#include<stdio.h>

// void quuicksort(int *arr,int begin,int end){
//     int i=begin;
//     int j=end;
//     int index=begin;
//     while(i<j){
//         while(arr[index]>=arr[i] && i<j){
//             i++;
//         }
//         while(arr[index]<=arr[j] && i<j){
//             j--;
//         }
//         if(i<j){
//             int temp=arr[i];
//             arr[i]=arr[j];
//             arr[j]=temp;
//         }
//     }
//     int temp=arr[index];
//     arr[index]=arr[j];
//     arr[j]=arr[index];
//     if(i>begin) quuicksort(arr,begin,i-1);
//     if(j<end) quuicksort(arr,j+1,end);
// }
#define ARR_MAX_LEN 100

int cmp(const void* a, const void* b){
	return *(int*)a - *(int*)b;
}
int comparator(const void *p, const void *q)
{
    int arg1 = *(const int*)p;
    int arg2 = *(const int*)q;
 
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}
int GetMinSum(int *a1, int a1Len, int *a2, int a2Len, int k){

    int ret=0;
    int arr_sum[a1Len*a2Len];
    int index=0;
    for(int i=0;i<a1Len;i++){
        for(int j=0;j<a2Len;j++){
            arr_sum[index++]=a1[i]+a2[j];
        }
    }
    //quuicksort(arr_sum,0,a1Len*a2Len);
    qsort(arr_sum, a1Len*a2Len, sizeof(int), comparator);
    for(int i=0;i<k;i++){
        ret+=arr_sum[i];
    }
    return ret;
}
int main(void)
{
    int n[2];
    static int a[2][ARR_MAX_LEN];

    int i, j;
    for (i = 0; i < 2; i++) {
        if (scanf_s("%d", &n[i]) != 1) { return -1; }
        for (j = 0; j < n[i]; j++) {
            if (scanf_s("%d", &a[i][j]) != 1) { return -1; }
        }
    }

    int k;
    if (scanf_s("%d", &k) != 1) { return -1; }

    int ret = GetMinSum(a[0], n[0], a[1], n[1], k);
    (void)printf("%d", ret);
    return 0;
}