//map按值排序
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
 
typedef pair<string, int> PAIR;  
 
int cmp(const PAIR& x, const PAIR& y)//针对PAIR的比较函数
{  
    return x.second > y.second;  //从大到小
}  
 
int main() {  
  map<string,int> nmap; 
 
  nmap["LiMin"] = 90;  
  nmap["ZiLinMi"] = 79;  
  nmap["BoB"] = 92;  
  nmap.insert(make_pair("Bing",99));  
  nmap.insert(make_pair("Albert",86));  
  //把map中元素转存到vector中   
  vector<PAIR> vec(nmap.begin(),nmap.end());
  sort(vec.begin(), vec.end(), cmp); //排序
  
  for (size_t i = 0; i != vec.size(); ++i) {  //输出
       cout << vec[i].first <<" "<<vec[i].second<<endl;  
  }  
 
  return 0;  
}