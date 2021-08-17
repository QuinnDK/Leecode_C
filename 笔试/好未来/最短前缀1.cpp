#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*字符串分割函数*/
void split(const std::string& s, std::vector<std::string>& v,
            const std::string& c)
{
  std::string::size_type pos1, pos2;
  pos2 = s.find(c);
  pos1 = 0;
  while(std::string::npos != pos2)
  {
    v.push_back(s.substr(pos1, pos2-pos1));
    pos1 = pos2 + c.size();
    pos2 = s.find(c, pos1);
  }
  if(pos1 != s.length())
    v.push_back(s.substr(pos1));
}

/*
建立一个数组用来保存字符串与其他字符串的最大匹配元素个数，
例如有四个字符串，第一个与第二、三、四个字符串进行逐字符比较，找出最大匹配的元素个数，存放到该数组中，之后第二个与第三、四个进行比较，
如果匹配元素比数组中的值大则更新数组中的值，否则不改变数组中的值。
循环结束后，数组中的元素就代表其唯一标识的字符个数，并将每个字符标识输出即可。
*/

int main(void)
{
    string str;
    vector<string> vstrs;
    //int *match_count_arr = nullptr;
    int once_match_count = 0;
    int i = 0;

    cin >> str;
    split(str, vstrs, ",");
    cout << vstrs.size()  << endl;
    vector<int> match_count_arr(vstrs.size());
    //match_count_arr = new int[vstrs.size()];//构建字符数组用于保存字符最大匹配个数
    for(i = 0; i < vstrs.size(); i++)
        match_count_arr[i] = 0;//将数组元素清零

    for(i = 0; i < vstrs.size(); i++){
        for(int j = i+1; j < vstrs.size(); j++){
            once_match_count = 0;
            while(vstrs[i][once_match_count] == vstrs[j][once_match_count])
                once_match_count++;
            if(match_count_arr[i] < once_match_count)
                match_count_arr[i] = once_match_count;
            if(match_count_arr[j] < once_match_count)
                match_count_arr[j] = once_match_count;
        }
    }
    for(i = 0; i < vstrs.size()-1; i++)
        cout << vstrs[i].substr(0, match_count_arr[i]+1) << ",";
    cout << vstrs[i].substr(0, match_count_arr[i]+1) << endl;

    // delete[] match_count_arr;
    // match_count_arr = nullptr;
    return 0;
}
