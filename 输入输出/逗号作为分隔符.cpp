#include<iostream>
using namespace std;

int main(){
    char a[5][10];
    int i;
    for (i=0;i<4;i++) cin.getline(a[i],10,',');
    cin.getline(a[i],10);
    for (i=0;i<5;i++){
        cout<<a[i]<<endl;
    }
}