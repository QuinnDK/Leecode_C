#include<iostream>
#include<string>
#include<vector>
using namespace std;


void char_to_string(){
    char ch[]="asdas  world";
    string str;
    str=ch;
    cout<< str <<endl;
}

void string_to_char(){
    string str="hello world";
    char ch[str.size()];
    strcpy(ch,str.c_str());
    for (int i=0;i<sizeof(ch);i++){
        cout<<ch[i]<<" ";
    }
    cout<<endl;
    string str2="100";
    int num=stoi(str2);
    cout<<num<<endl;
}

int  main(){
    char_to_string();
    string_to_char();



    // string s;
    // char ss[20];
    //cin>>s;
    //getline(cin,s);
    //cin.getline(ss,10);

    // int lenth=s.size();
    // for(int i=0;i<lenth;i++){
    //     cout<<s[i]<<"\n";
    // }
    // if (!s.empty()){
    //     cout<<"s is not empty"<<endl;
    // }
    // s.resize(20,'c');
    //cout<<ss<<endl;
    // string str ="abcd ef K";
    // str.append("ads");
    // cout<<str;
    // cout<<"=====================\n";
    // string str1="123";
    // str.swap(str1);
    // cout<<str<<"     "<<str1;
    // cout<<"===========================\n";
    //vector<vector<int> > dp;

    // string str3="abc123defg";
    // cout<<str3.erase(3,3)<<endl;  //从索引3开始的3个字符,即删除掉了"123"
    // cout<<str3.insert(0,"123")<<endl; //在头部插入
    // cout<<str3.append("123")<<endl;//append()方法可以添加字符串
    // cout<<str3.replace(0,3,"hello")<<endl;
    // cout<<std::to_string(555)<<endl;


}
