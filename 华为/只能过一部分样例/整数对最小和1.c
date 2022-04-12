#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define ARR_MAX_LEN 100

int cmp(const void* a, const void* b){
	return *(int*)a - *(int*)b;
}
int GetMinSum(int* arr1, int len1, int* arr2, int len2, int k){
	int i, j, idx = 0;
	int* list = NULL;
	int len = sizeof(int) * len1 * len2;
	int result = 0;
	list = malloc(len);
	if (list == NULL)
		return -1;
	memset(list, 0, len); //初始化数组
	for (i = 0; i < len1; i++){
		for (j = 0; j < len2; j++){
			list[idx] = arr1[i] + arr2[j];
			idx++;
		}
	}
	qsort(list, len1*len2, sizeof(list[0]), cmp);
	for (i = 0; i < k; i++){
		result += list[i];
	}
	return result;
	free(list);
}
int main(void){
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
