#include <iostream>
#include<cmath>
 
using namespace std;
 
int main() {
    int N,E,X,offsetY,area,preX=0,curY=0;
    cin>>N>>E;
    for (int i=0; i<N; ++i) {
        cin>>X>>offsetY;
        area += (X-preX)*abs(curY);
        preX = X;
        curY += offsetY;
    }
    if(preX<E){
        area += (E-preX)*abs(curY);
    }
    cout<<area<<endl;
    return 0;
}