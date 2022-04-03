#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include <limits.h>

#define BUF_LEN 650000
#define MAX_N 102400

int comparator(const void *p, const void *q)
{
    int arg1 = *(const int*)p;
    int arg2 = *(const int*)q;
 
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}
int Proc(int *arr, int arrLen, int diff) 
{
    int i, j;
    int resTmp;
    qsort(arr, arrLen, sizeof(int), comparator);
    diff = fabs(diff);
    int r = 0;
    int l = 0;
    int cnt = 0;

    while (r < arrLen) {
            if (r == l) {
                r++;
                continue;
            }
            if (arr[r] - arr[l] < diff) {
                r++;
            } else if (arr[r] - arr[l] == diff) {
                cnt++;
                r++;
            } else {
                while (arr[r] - arr[l] > diff && l < r) {
                    l++;
                }
            }
    }

    return cnt;
}

int main(void)
{
    int diff;
    if (scanf_s("%d\n", &diff) != 1) { return -1; };

    int n;
    if (scanf_s("%d\n", &n) != 1) { return -1; };

    static char buf[BUF_LEN];
    static int arr[MAX_N];
    int i = 0;
    char *sep = " ";
    char *sec = NULL;
    char *nt = NULL;
    if (gets_s(buf, sizeof(buf)) == NULL) {
        return -1;
    }
    sec = strtok_s(buf, sep, &nt);
    while (sec != NULL) {
        arr[i++] = atoi(sec);
        sec = strtok_s(NULL, sep, &nt);
    }

    int ret = Proc(arr, n, diff);
    (void)printf("%d", ret);
    return 0;
}
