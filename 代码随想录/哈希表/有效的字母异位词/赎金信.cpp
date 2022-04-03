#include<bits/stdc++.h>
using namespace std;

bool canConstruct(string ransomNode,string magezine){
    vector<int> hashTable(26,0);
    
    for(auto& x:magezine){
        hashTable[x-'a']++;
    }
    for(auto& x :ransomNode){
        hashTable[x-'a']--;
        if(hashTable[x-'a']<0){
            return false;
        }
    }
    return true;
}