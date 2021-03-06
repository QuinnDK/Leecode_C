#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;

vector<int> findAnagrams(string s,string t){
    unordered_map<char,int>need,window;
    int left=0,right=0;
    int valid=0;

    for (char c:t){
        need[c]++;
    }

    vector<int>res;
    while(right<s.size()){
        char c=s[right];
        right++;
        
        if (need.count(c)){
            window[c]++;
            if (window[c]==need[c]){
                valid++;
            }
        }
        while(right-left>=t.size()){
            if (valid==need.size()){
                res.push_back(left);
            }
            char d=s[left];
            left++;
            if (need.count(d)){
                if (window[d]==need[d]){
                    valid--;
                }
                window[d]--;
            }
        }
    }
    return res;
}