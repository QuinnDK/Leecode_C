#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    vector<int> nums = {2,2,3,30};

    sort(nums.begin(), nums.end(), [](int a, int b){
        string astr = to_string(a);
        string bstr = to_string(b);

        return astr + bstr > bstr + astr;
    });


    for(auto x : nums) cout << x << " ";
    cout << endl;

    int sz = nums.size();
    string res = "";
    for(int i = 0; i < sz; i++) {
        res += to_string(nums[i]);
    }
    int i;
    for(i = 0; i < sz; i++) {
        if(res[i] != '0') break;
    }

    if(i == sz) cout << "0" << endl;
    cout << res << endl;
    return 0;
}