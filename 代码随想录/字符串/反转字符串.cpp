#include<bits/stdc++.h>
using namespace std;

void reverseString(vector<char> & s){
    for(int i=0,j=s.size()-1;i<j;i++,j--){
        swap(s[i],s[j]);
    }
}

/*
swap(s[i],s[j]);

s[i] ^= s[j];
s[j] ^= s[i];
s[i] ^= s[j];

int tmp = s[i];
s[i] = s[j];
s[j] = tmp;
*/