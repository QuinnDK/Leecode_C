#include<bits/stdc++.h>
using namespace std;


//去掉多余空格
void removeExtraSpaces(string& s){
    //首先删除连续的空格
    for(int i = 0;i < s.size(); i++){
        if(s[i] == s[i + 1] && s[i] == ' '){  
            s.erase(s.begin() + i);
            i--;   //由于删除了一个空格，所以i要前移一位才能
        }
    }
    //删除字符串末尾的空格
    if(s.size() > 0 && s[s.size() - 1] == ' '){
        s.erase(s.begin() + s.size() - 1);
    }
    //删除字符串开头的空格
    if(s.size() > 0 && s[0] == ' '){
        s.erase(s.begin());
    }
}

string reverseWords(string s) {
removeExtraSpaces(s);     //去掉多于空格
reverse(s.begin(),s.end());   //翻转整个字符串
//开始处理每个单词的翻转
int start = 0;
for(int i = 0;i < s.size(); i++){
    if(s[i] == ' ' ){
        reverse(s.begin() + start ,s.begin() + i );
        start = i + 1;
    }
    if(i == (s.size() - 1) ){
        reverse(s.begin() + start,s.begin() + i + 1);
    }
}
return s;
}