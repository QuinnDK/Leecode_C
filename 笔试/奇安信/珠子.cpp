#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int dis(vector<pair<int, int> >& grid, int i, int j, int k) {
    int res = 0;
    res += abs(grid[j].first - grid[i].first) + abs(grid[j].second - grid[i].second);
    res += abs(grid[k].first - grid[j].first) + abs(grid[k].second - grid[j].second);
    return res;
}

int main(){
     int n;
     cin >> n;
     //memset(grid, 0, sizeof grid);
     vector<pair<int,int> > grid;
     for(int i = 0; i < n; i++) {
         int x, y;
         cin >> x >> y;
         grid.push_back(make_pair(x, y));
     }
     sort(grid.begin(), grid.end());
    int sz = grid.size();
    int res = INT_MAX;
    for(int i = 0; i < sz - 2; i++) {
        for(int j = i + 1; j < sz - 1; j++) {
            for(int k = j + 1; k < sz; k++) {
                res = max(res, dis(grid, i, j, k));
            }
        }
    }
    cout << res << endl;
     
}