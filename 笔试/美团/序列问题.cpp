#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> data(N);
    for (int i=0;i<N;i++){
        cin>>data[i];
    }

    set<int>s;
    int ans=0;

    for (int i=0;i<N;i++){
        auto it=s.lower_bound(data[i]);
        if (it !=s.begin()){
            ans+=(*(--it)*(i+1));
        }
        s.insert(data[i]);

    }
    cout<<ans<<endl;
    return 0;
}