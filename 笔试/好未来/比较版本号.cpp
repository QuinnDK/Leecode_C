#include<iostream>
#include<string>
using namespace std;


int compareVersion(string &version1,string &version2){
    int n1=version1.size(),n2=version2.size();
    int cur1=0,cur2=0;

    while (cur1<n1 || cur2<n2){
        int num1=0,num2=0;
        while(cur1<n1 && version1[cur1]!='.'){
            num1=num1*10+version1[cur1]-'0';
            cur1++;
        }
         while(cur2<n2 && version2[cur2]!='.'){
            num2=num2*10+version2[cur2]-'0';
            cur2++;
        }
        if (num1<num2) return -1;
        if (num1>num2) return 1;
        cur1++;
        cur2++;

    }
    return 0;
}

int main(){
    string s1,s2;
    cin>>s1>>s2;
    int res =compareVersion(s1,s2);
    cout<<res;
}