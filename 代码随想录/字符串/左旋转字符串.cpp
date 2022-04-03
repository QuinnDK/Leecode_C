#include<bits/stdc++.h>
using namespace std;

string reverseLeftWords(string s, int n) {
    reverse(s.begin(),s.end());
    reverse(s.begin(),s.begin()+(s.size()-n));
    reverse(s.begin()+(s.size()-n),s.begin()+s.size());

    return s;
}

// int main(){
//     string s="abcdefg";

//     cout<<s.size();
// }