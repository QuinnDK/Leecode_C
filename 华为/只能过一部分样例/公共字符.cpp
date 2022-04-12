#include<bits/stdc++.h>
using namespace std;

vector<char> GetNTimesCharacter(int n, const vector<string> &strings)
{
    vector<char> result;

    int lenStrings=strings.size();
    vector<set<char> > Hash(lenStrings);
    for(int i=0;i<lenStrings;i++){
        string str=strings[i];
        unordered_map<char,int> map;
        for(int j=0;j<str.size();j++){
            if(map.count(str[j])){
                map[str[j]]++;
            }else{
                map.insert(make_pair(str[j],1));
            }
            if(map[str[j]]>=n){
                Hash[i].insert(str[j]);
            }
        }   
    }
    for(int i=0;i<lenStrings;i++){
        for_each(Hash[i].begin(),Hash[i].end(), [](char x)){
            
        }
    }
    
    return result;
}