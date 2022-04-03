#include<bits/stdc++.h>
using namespace std;

struct Package {
    int fragType; // 数据类型
    int fragOffset; // 分段序号
    int finish; //  结束标志
    int length; // 长度
    string data; // 数据
};

class Solution {
public:
    // 待实现函数,在此函数中填入答题代码;
    string ReassembleData(const vector<Package> &records, int packageType)
    {
        string result;
        vector<pair<int,string> > ret;
        bool flag=false;
        for(int i=0;i<records.size();i++){
            if(records[i].fragType==packageType){
                flag=true;
            }
            if(flag && records[i].fragType==packageType) ret.push_back(make_pair(records[i].fragOffset,records[i].data));
        }
        if(flag==false){
            return "NA";
        }
        sort(ret.begin(),ret.end());
        if(ret[0].first!=0){
            result="NA";
        }else{
            int slow=1;
            for(int fast=1;fast<ret.size();fast++){
                if(ret[fast].first!=ret[fast-1].first){
                    ret[slow++]=ret[fast];
                }
            }
            for(int i=0;i<records.size();i++){
                if(records[i].finish!=1 && records[i].data==ret[slow-1].second){
                    return "NA";
                }
            }
            result+=(ret[0].second);
            for(int i=1;i<slow;i++){
                if(ret[i].first==ret[i-1].first+1){
                    result+=ret[i].second;
                }else{
                    result="NA";
                }
            }

        }
        return result;
    }
};

// 以下为考题输入输出框架，此部分代码不建议改动
int main()
{
    int num;
    cin >> num;

    vector<Package> records;
    for (int loop = 0; loop < num; loop++) {
        Package rec;
        cin >> rec.fragType >> rec.fragOffset >> rec.finish >> rec.length >> rec.data;
        records.push_back(rec);
    }
    int packageType; // 指定数据类型
    cin >> packageType;
    
    Solution solu;
    string result  = solu.ReassembleData(records, packageType);
    cout << result << endl;
    return 0;
}
