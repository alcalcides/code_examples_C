#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> dias;

    dias.push_back(100);
    dias.push_back(5);
    dias.push_back(500);
    
    cout << dias[0] << endl; // 100

    for (auto dia : dias)
    {
        cout << dia << ", "; // 100, 5, 500
    }
    cout << endl;


    vector<int> nums(4,-1); // nums = [-1, -1, -1, -1]
    nums[1] = 30;
    for (auto num : nums)
    {
        cout << num << ", "; // -1, 30, -1, -1
    }
    cout << endl;
    

    return 0;
}
