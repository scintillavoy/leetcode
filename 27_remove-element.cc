#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>::size_type len = nums.size();
        for (vector<int>::size_type i = 0; i < len; ++i) {
            while (nums[i] == val && i < len) {
                swap(nums[i], nums[--len]);
            }
        }
        return len;
    }
};

int main() {
    Solution sol;
    vector<int> vec{2, 2, 2};
    cout << sol.removeElement(vec, 2) << endl;
    for (auto const &x : vec) {
        cout << x << ' ';
    }
    cout << endl;
    return 0;
}
