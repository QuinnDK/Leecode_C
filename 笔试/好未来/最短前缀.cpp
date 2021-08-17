#include<bits/stdc++.h>
using namespace std;

int main(){
    string t;
    vector<string> s;
    while (cin>>t){
        s.push_back(t);
    }

    int n=s.size();
    string ans[n];
    int commonLength;
    int flag;
    for (int i=0;i<n;i++){
        flag++;
        commonLength=0;
        if (ans[i].size()>0) continue;
        else{
            while(flag){
                for (int j=0;j<n;++j){
                    flag=0;
                    if(i==j) continue;
                    else{
                        if (commonLength==s[i].size()){
                            ans[i]=s[i];
                            flag=0;
                            break;
                        }else if(commonLength==s[j].size()){
                            continue;
                        }else if(s[j].find(s[i].substr(0,commonLength+1))==0){
                            flag=1;
                            break;
                        }else{
                            continue;
                        }
                    }
                }
                if(flag){
                    commonLength++;
                }
            }
            ans[i]=s[i].substr(0,commonLength+1);
        }
    }
    for(int i=0;i<n;++i){
        cout<<s[i]<<" "<<ans[i]<<endl;
    }
    return 0;
}