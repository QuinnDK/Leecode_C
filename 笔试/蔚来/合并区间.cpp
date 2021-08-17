#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> > merge(vector<vector<int> >& intervals) {
    int len=intervals.size();
    if(len==1 || len==0){
        return intervals;
    }
    sort(intervals.begin(),intervals.end());

    vector<vector<int> > res;
    vector<int> temp;
    int left=intervals[0][0];
    int right=intervals[0][1];
    for( int i=1;i<len;i++){
        if(intervals[i][0]<=right){
            if(intervals[i][1]>=right){
                right=intervals[i][1];
            }
        }else{
            res.push_back( vector<int>{left,right});
            left=intervals[i][0];
            right=intervals[i][1];
        }
    }
    res.push_back(vector<int >{left,right});
    return res;

}