#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

bool isvalid(string x){
    stack<int> d;
    for (int i=0;i<x.size();i++){
        if (x[i]=='('){
            d.push(i);
        }else{
            if(d.empty()){
                return false;
            }else{
                d.pop();
            }
        }
        if(!d.empty()){
            return false;
        }
        return true;
    }
}

int main(){
    int n;
    cin>>n;
    string temp;
    cin>>temp;

    int k=0;
    vector<int> res;
    for(int i=0;i<temp.size();i++){
        string x=temp;
        x.erase(x.begin()+i);
        if (isvalid(x)){
            res.push_back(i);
            k++;
        }
    }
    cout<<k<<endl;
    for(auto& c:res){
        cout<<c+1<<" ";
    }
}