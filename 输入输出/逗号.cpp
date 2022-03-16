#include <iostream>
#include <vector>
#include<sstream>

using namespace std;

int main(){
    string str;
    cin>>str;
    stringstream t(str);
    vector<int> nums;

    while(getline(t,str,',')){
        int t=stoi(str);
        nums.push_back(t);
    }
}
    // int t = 0;
    // int l = 0;
    // while(l < str.size()) {

    //     if(str[l] == ',') {
    //         nums2.push_back(t);
    //         t = 0;
    //     } else {
    //         t = t * 10 + str[l] - '0';
    //     }   
    //     l++;
    // }
    // nums2.push_back(t);