#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solution(vector<int> & a, int n)
{
    int cnt = 0;  
    vector<int> v;
    v.reserve(n);

    int low = 0;  
    for (int i = 0; i < n; i++)
    {    
        v.clear();
       
        v.push_back(a[i]);
        for (int j = i - 1; j >= low; j--)
        {
            v.push_back(v.back() & a[j]);
        }
        if (find(v.begin(), v.end(), 0) != v.end())
        {    
            cnt++;
            low = i + 1;  
        }
    }
    cout << cnt << endl;
}


int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    solution(v, n);
    return 0;
}
