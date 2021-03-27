#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> candidates;
        for (int i = 0; i < nums.size(); ++i) {
            while (!candidates.empty() && nums[candidates.back()] <= nums[i]) {
                candidates.pop_back();
            }
            candidates.push_back(i);
            if (i >= k-1) {
                ans.push_back(nums[candidates.front()]);
            }
            if (candidates.front() <= i-k+1) {
                candidates.pop_front();
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}
