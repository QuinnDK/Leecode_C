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
        while(window[c]>1){
            char d=s[left];
            left++;
            window[d]--;
        }
        res=max(res,right-left);
    }
    return res;
}