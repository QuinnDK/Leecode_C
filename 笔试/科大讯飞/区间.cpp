#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int findInterval(string s){
    unordered_map<char,int> need,window;
    string temp="abcdefghijklmnopqrstuvwxyz";

    for (auto c:temp) need[c]++;
    int len=INT_MAX;
    int left=0;
    int right=0;
    int valid=0;
    int  count=0;
    while(right<s.size()){
        char c=s[right];
        right++;
        if(need.count(c)){
            window[c]++;
            if (window[c]==need[c]){
                valid++;
            }
        }else if(c=='?'){
            count++;
            window[c]++;
        }
        while(valid+count==need.size()){
            if (right-left<len){
                len=right-left;
            }
            char d=s[left];
            left++;
            if(need.count(d)){
                if(window[d]==need[d]){
                    valid--;
                }
                window[d]--;
            }else if (d=='?'){
                count--;
                window[d]--;
            }
        }
    }
    return len==INT_MAX ? -1:len;
}
// 输入：abcdefghigklmnopqrstuvwwwxyz   输出：-1
// 输入： abcdefghigklmnopqrstuv????xyz. 输出：27
int main(){
    string s="aaabbbcdefghijgklmnopqrstuvwwwxyz";
    cout<<findInterval(s) << endl;
}
