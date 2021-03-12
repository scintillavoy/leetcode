#include <vector>
using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(nums.size());
        for (int i = 0; i < n; ++i) {
            ans[2*i] = nums[i];
            ans[2*i+1] = nums[i+n];
        }
        return ans;
    }
};

int main() {
    return 0;
}

/**
 * 0 1 2 3 4 5 6 7
 * a b c d A B C D
 * a A b B c C d D
 * 
 * 
 */
