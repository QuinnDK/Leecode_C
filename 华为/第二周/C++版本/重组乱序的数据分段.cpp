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
    string ReassembleData(vector<Package> &records, int packageType)
    {
        string result;
        //排序
        sort(records.begin(),records.end(),[](const Package& a,const Package& b){
            if(a.fragType!=b.fragType){
                return a.fragType<b.fragType;
            }else if(a.fragOffset!=b.fragOffset){
                return a.fragOffset<b.fragOffset;
            }else{
                return a.finish<b.finish;
            }
        });
        for(int i=0;i<records.size();i++){
            cout<<records[i].fragType<<" "<<records[i].fragOffset<<" "<<records[i].finish<<" "<<records[i].length<<" "<<records[i].data<<endl;
        }
        if(records[records.size()-1].fragType<packageType){
            return "NA";
        }
        int slow =0;
        int fast =0;
        for(int i=0;i<records.size();i++){
            if(records[i].fragType==packageType){
                fast=i;
                break;
            }
        }
        slow=fast;
        if(records[slow].fragOffset!=0){
            return "NA";
        }
        for(int i=slow;i<records.size();i++){
            if(records[i].fragType!=packageType){
                break;
            }else{
                fast=i;
            }
        }

        int end=fast;
        int start=slow;
        queue<Package> que;
        for(int i=start;i<=end;i++){
            if(que.empty()){
                que.push(records[i]);
            }else if(que.back().fragOffset+1==records[i].fragOffset ){
                que.push(records[i]);
            }
        }
        if(que.back().finish!=1){
            return "NA";
        }
        // while (!que.empty()) {
		//     cout << que.front().data << " ";
		//     que.pop();
	    // }

        while(!que.empty()){
            if(que.front().finish==0){
                result+=que.front().data;
                que.pop();
            }else{
                result+=que.front().data;
                que.pop();
                if(!que.empty()){
                    result="NA";
                    break;
                }
            }
        }
        // while(start<end){
        //     if(records[start].finish==1){
        //         return "NA";
        //     }else{
        //         start++;
        //     }
        // }
        //cout<<start<<" "<<end<<endl;
        
        //result+=records[slow].data;
        // for(int i=slow;i<=fast;i++){
        //     cout<<records[i].fragType<<" "<<records[i].fragOffset<<" "<<records[i].finish<<" "<<records[i].length<<" "<<records[i].data<<endl;
        // }
        // for(int i=slow+1;i<=fast;i++){
        //     if(records[i].fragOffset!=records[i-1].fragOffset){
        //         result+=records[i].data;
        //     }
        // }

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
