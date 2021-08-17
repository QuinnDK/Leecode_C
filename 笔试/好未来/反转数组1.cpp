#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    string str;
    cin >>str;
    int k;
    cin >>k;
    int lenth=str.size();
    vector<int> res;
    int temp=0;

    for (int i=0;i<lenth;i++){
        if (str[i]==','){
            res.push_back(temp);
            temp=0;
            continue;
        }else{
            temp=temp*10 +str[i]-'0';
        }
    }
    res.push_back(temp);

    int start=res.size()-(k%res.size());
    int len2=res.size()+start;

    int i;
    for ( i=start;i<len2;i++){
        cout<<res[i%res.size()]<<",";
    }
    cout<<res[i %res.size()];
    return 0;
}