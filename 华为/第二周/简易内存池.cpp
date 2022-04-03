#include<bits/stdc++.h>
using namespace std;
#define Address_DEFAULT_HEAD 0;
#define Address_DEFAULT_END 100;

class MiniMemoryPool {
public:
    // 返回分配的内存首地址,失败返回 -1
    vector<bool> flags=vector<bool>(100,false);
    map<int,pair<int,int> > addressmap;
    int Request(int size)
    {
        if(size<0) return -1;
        for(int i=0;i<flags.size();){
            if(!flags[i]){
                int count=0;
                int init=i;
                for(int j=i;i<flags.size();j++,i++){
                    if(!flags[j]){
                        count++;
                        if(count==size){
                            for(int k=0;k<size;k++){
                                flags[k+init]=true;
                            }
                            addressmap[init]=make_pair(init,size);
                            return init;
                        }
                    }else{
                        break;
                    }
                }
            }else{
                i++;
            }
        }
        return -1;
    }
  
    // 释放内存地址, 成功返回 true, 失败返回 false
    bool Release(int startAddr){
        if(addressmap.count(startAddr)){
            pair<int,int> Add=addressmap[startAddr];
            for(int i=Add.first;i<Add.first+Add.second;i++){
                flags[i]=false;
            }
            //return Add.first;
            return true;
        }
        return false;
    }
};

int main()
{
    int num;
    cin >> num;

    MiniMemoryPool pool;
    for (int loop = 0; loop < num; loop++) {
        string line;
        cin >> line;

        string commond = line.substr(0, line.find_first_of('='));
        if (commond == "REQUEST") {
            int size = stoi(line.substr(line.find_first_of('=')+1));
            int result = pool.Request(size);
            if (result != -1) {
                cout << result << endl;
            } else {
                cout << "error" << endl;
            }
        } else if (commond == "RELEASE") {
            int addr = stoi(line.substr(line.find_first_of('=')+1));
            if (!pool.Release(addr)) {
                cout << "error" << endl;
            }
        }
    }

    return 0;
}
