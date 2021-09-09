#include<iostream>
#include<vector> 

using namespace std;


int main(){
    int T;
    cin>>T;
    while(T--){
        int min=INT_MAX;
        int max=INT_MIN;
        int N;
        cin>>N;
        while(N--){
            int D,K;
            cin>>D>>K;
            if (D>=max){
                max=D;
            }
            if(D<=min){
                min=D;
            }
            vector<int> KI(K);
            for(int i=0;i<K;i++){
                cin>>KI[i];
            }
        }
        cout<<min+max<<endl;
    }
    return 0;
}