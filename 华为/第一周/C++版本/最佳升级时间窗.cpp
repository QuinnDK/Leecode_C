#include<bits/stdc++.h>
using namespace std;
#define ARR_LEN (7 * 24)

int real_length(int &l, int &r)
{
    if (l > ARR_LEN - 1) {
        return 0;
    }
    if(r >= ARR_LEN && l <= r % ARR_LEN) {
        return 168;
    }
    return r - l + 1;
}

vector<int> GetBestTimeWindow(int n, const vector<int> &arr) const
{
    // 在此添加你的代码
    vector<long double> arr2(ARR_LEN * 2, 0);
    int size2 = arr2.size();
    for (int i = 0; i < size2; ++i) {
        arr2[i] = arr[i % ARR_LEN];
    }

    int l = 0, r = 0;
    long double sum = arr2[l];

    vector<int> result(2, -1);

    int max_len = 0;
    int tmp = 0;

    while(r < size2 - 1) {
        if (sum > n) {
            if (l == r) {
                l++;
                r++;
                sum = arr2[l];
            } else {
                sum -= arr2[l];
                l++;
            }
        } else {
            if ((tmp = real_length(l, r)) > max_len) {
                result[0] = l;
                result[1] = r % ARR_LEN;
                max_len = tmp;
            }

            r++;
            sum += arr2[r];
        }
    }
    return result;
}
