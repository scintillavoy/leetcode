#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_idx = 0;
        for (int i = 0; i <= max_idx; ++i) {
            max_idx = max(max_idx, i + nums[i]);
            if (max_idx >= nums.size()-1) return true;
        }
        return false;
    }
};

int main() {
    return 0;
}
