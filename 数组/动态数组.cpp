#include<iostream>
#include<vector>

using namespace std;

void Printnum(vector<int> arr);

int main(){
    vector<int> arr;
    for(int i=0;i<17;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    Printnum(arr);
    cout<<arr.capacity()<<endl; //16
    for(int i=0;i<5;i++){
        arr.pop_back();
    }
    Printnum(arr);
    cout<<arr.capacity()<<endl;
}

void Printnum(vector<int> arr){
    for (int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}