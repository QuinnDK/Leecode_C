// 小顶堆
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class greater_class{
public:
    bool operator()(int a, int b)
    {
        return a > b;
    }
};
void printVector(vector<int> &num)
{
    for(int i = 0; i < num.size(); i++)
        cout<<num[i]<<" ";
    cout<<endl;
}

int main()
{
    // init
    int arr[] = {5,1,6,9,4,3};
    vector<int> num(arr,arr+6);
    printVector(num);

    make_heap(num.begin(), num.end(), greater_class());
    printVector(num); // 1 4 3 9 5 6 

    num.push_back(2);
    printVector(num); // 1 4 3 9 5 6 2
    push_heap(num.begin(),num.end(),greater_class());
    printVector(num); // 1 4 2 9 5 6 3 

    while (num.size())
    {
        pop_heap(num.begin(),num.end(),greater_class());
        long min = num.back();
        num.pop_back();  
        cout << min << std::endl;
    } // 1 2 3 4 5 6 9
}