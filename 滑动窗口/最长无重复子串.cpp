#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int main(){

}
int lenthOfLongestSubstring(string s){
    unordered_map<char,int>window;
    int left=0,right=0;

    int res=0;
    while(right<s.size()){
        char c=s[right];
        right++;
        window[c]++;
        while(window[c]>1){
            char d=s[left];
            left++;
            window[d]--;
        }
        res=max(res,right-left);
    }
    return res;
}

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxsub = 0, left = 0, pos = 0;
        vector<bool> used(256, false);
        while(pos < s.size()){
            while(used[s[pos]]) used[s[left++]] = false;  
            maxsub = max(maxsub, pos - left + 1);
            used[s[pos++]] = true;
        }
        return maxsub;
    }
};

