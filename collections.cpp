#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(20);
    nums.push_back(200);

    sort(nums.begin(), nums.end());
    reverse(nums.begin(), nums.end());

    for (auto num : nums)
    {
        cout << num << endl;
    }
    




    return 0;
}