#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

long sumvector(vector<int>& record, int left, int right) {
    long sum = 0;
    while (left <= right) {
        sum += record[left];
        left++;
    }
    return sum;
}

int main() {
    int n = 0, k = 0;
    cin >> n >> k;
    vector<int> record;
    vector<int> res(2, 0);
    double average = -1.0;
    while (n--) {
        int tmp;
        cin >> tmp;
        record.push_back(tmp);
    }
    for (int j = k - 1; j < record.size(); j++) {
        int left = 0, right = j;
        while (right < record.size()) {
            long cursum = sumvector(record, left, right);
            double curaverage = cursum / (right - left + 1);
            if (curaverage >= average) {
                res[0] = left;
                res[1] = right;
                average = curaverage;
            }
            if (abs(curaverage - average) < 0.0001) {
                if (right - left > res[1] - res[0]) {
                    res[0] = left;
                    res[1] = right;
                }
                if (right - left == res[1] - res[0]) {
                    if (left < res[0]) {
                        res[0] = left;
                        res[1] = right;
                    }
                }
            }
            left++;
            right++;
        }
    }
    cout << res[0] << " " << res[1];
    return 0;
}