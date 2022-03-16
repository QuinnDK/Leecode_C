#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<string> stk;
    while(n--){
        string str;
        cin>>str;
        if(str=="cd"){
            string dir;
            cin >> dir;
            if(dir == "..") {
                if(stk.size())
                	stk.pop_back();
            } else {
                stk.push_back(dir);
            }
        } else {
            if(stk.size()) {
               for(auto x : stk) {
                cout << "\\" << x;
               }
               cout << endl; 
            } else {
                cout << "\\" << endl;
            }
            
        }
    }
    return 0;
}