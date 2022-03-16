#include<iostream>
#include<vector>
using namespace std;

int mySqrt(int x){
    int left=0;
    int right=x/2;
    int res=-1;
    while(left<=right){
        int middle=left+(right-left)/2;
        if(middle*middle<=x){
            res=middle;
            left=middle+1;
        }else{
            right=middle-1;
        }
    }
    return res;
}

int main(){

}