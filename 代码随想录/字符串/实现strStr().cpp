#include<bits/stdc++.h>
using namespace std;

// int strStr(string haystack, string needle) {
//     int lenNeedle=needle.size();
//     int res=-1;
//     if(haystack=="" && haystack==needle){
//         return 0;
//     }
//     for(int i=0;i<haystack.size()-lenNeedle;i++){
//         if(haystack.substr(i,i+lenNeedle)==needle){
//             res=i;
//             break;
//         }
//     }
//     return res;
// }

int strStr(string haystack, string needle) {
    int n = haystack.size(), m = needle.size();
    for (int i = 0; i + m <= n; i++) {
        bool flag = true;
        for (int j = 0; j < m; j++) {
            if (haystack[i + j] != needle[j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            return i;
        }
    }
    return -1;
}
