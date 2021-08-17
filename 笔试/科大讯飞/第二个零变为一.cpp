#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int x=0,m=1;
    while (1){
        if ((m&n)==0){
            x++;
            if (x==2) break;
        }
        m=m<<1;
    }
    cout<< n+m << endl;
    return 0;
}