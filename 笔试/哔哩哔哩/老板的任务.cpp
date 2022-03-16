#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;
class Solution {
public:
    /* Write Code Here */
    vector < int > GetLeastNumbers(vector < int > input, int k) {
        
    }
}
int main() {
    vector < int > res;

    int _input_size = 0;
    cin >> _input_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _input;
    int _input_item;
    for(int _input_i=0; _input_i<_input_size; _input_i++) {
        cin >> _input_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _input.push_back(_input_item);
    }


    int _k;
    cin >> _k;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');

    
    Solution s = new Solution();
    res = s.GetLeastNumbers(_input, _k);
    for(int res_i=0; res_i < res.size(); res_i++) {
    	cout << res[res_i] << endl;;
    }
    
    return 0;

}