#include<iostream>
using namespace std;

int main(){
    int curVal=0,val=0;
    if(cin>>curVal){
        int count=1;
        while(cin>>val){
            if(curVal==val){
                count++;
            }else{
                cout<< curVal <<" "<<count<<endl;
                curVal=val;
                count=1;
            }
        }
        cout<< curVal <<" "<< count <<endl;
    }
    return 0;
}