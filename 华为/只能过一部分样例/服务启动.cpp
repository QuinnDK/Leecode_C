#include<bits/stdc++.h>
using namespace std;


struct Server{
    int Serve;
    vector<int> ServiceDependence;
};

vector<int> GetServiceDependence(vector<Server> &Servers,int M);
int main(){
    int N,M;
    cin>>N>>M;
    vector<int> result;
    vector<Server> Servers(N);
    for(int i=0;i<N;i++){
        string s;
        cin>>s;
        int k=0;
        for(int j=0;j<s.size();j++){
            if(s[j]==','){
                k++;
                continue;
            }
            if(k==0){
                Servers[i].Serve=s[j]-'0';
            }else{
                Servers[i].ServiceDependence.push_back(s[j]-'0');
            }
        }

    }
    result=GetServiceDependence(Servers,M);
    if(!result.empty()){
        sort(result.begin(),result.end());
        for(int i=0;i<result.size();i++){
            if(i==0){
                cout<<result[i];
            }else{
                if(result[i]!=result[i-1]){
                    cout<<" "<<result[i];
                }
            }
        }
        
    }else{
        cout<<"-1"<<endl;
    }


}

vector<int> GetServiceDependence(vector<Server> &Servers,int M){
    vector<int> result;
    vector<int> temp;
    for(int i=0;i<Servers.size();i++){
        if(Servers[i].Serve==M){
            temp=Servers[i].ServiceDependence;
            break;
        }
    }
    if(temp.empty()){
        return result;
    }
    for(int i=0;i<temp.size();i++){
        result.push_back(temp[i]);
        vector<int> temp2=GetServiceDependence(Servers,temp[i]);
        for(int j=0;j<temp2.size();j++){
            result.push_back(temp2[j]);
        }
    }
    return result;
}
