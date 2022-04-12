#include<bits/stdc++.h>
using namespace std;

int search(vector<pair<string,pair<int,int> > >& writeList,string phone){
    int lenth=writeList.size();
    int res=-1;
    for(int i=0;i<lenth;i++){
        string str=writeList[i].first;
        if(str.back()=='*'){
            if(phone.find(str.substr(0,str.size()-1))!=string::npos){
                res=i;
            }
        }else{
            if(phone.find(str)!=string::npos){
                res=i;
            }
        }
    }
    return res;
}
bool search2(vector<string>& strPhone,string phone){
    int lenth=strPhone.size();
    for(int i=0;i<lenth;i++){
        string str=strPhone[i];
        if(str.back()=='*'){
            if(phone.find(str.substr(0,str.size()-1))==0){
                return true;
            }
        }else if(phone.find(str)==0){
            return true;
        }
    }
    return false;
}

int main(){
    int N;
    cin>>N;
    vector<pair<string,pair<int,int> > > writeList;
    vector<string> strPhone;
    for(int i=0;i<N;i++){
        char c;
        string phone;
        cin>>c>>phone;
        if(c=='C'){
            int index=search(writeList,phone);
            if(search2(strPhone,phone)){
                if(index==-1){
                    writeList.push_back({phone,{1,0}});
                }else{
                    writeList[index].second.first++;
                }
            }else{
                if(index==-1){
                    writeList.push_back({phone,{0,1}});
                }else{
                    writeList[index].second.second++;
                }
            }

        }else{
            strPhone.push_back(phone);
        }
    }
    for(int i=0;i<writeList.size();i++){
        cout<<writeList[i].first<<" "<< writeList[i].second.first<<" "<<writeList[i].second.second<<endl;
    }
    return 0;
}