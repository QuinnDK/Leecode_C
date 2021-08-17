#include<iostream>
#include<vector>

using namespace std;

int main(){
    string str;
    getline(cin,str);
    string ret;
    for(int i=0 ; i<str.size() ;i++){
        if(str[i] == ' ')
            continue;
        else{
            ret+=str[i];
            int tmp = i+1;
            while( tmp <str.size() && (str[tmp] == str[i] || str[tmp] == ' ') )
                tmp++;
            i = tmp-1;
        }
    }
    cout<<ret<<endl;
    return 0;
}