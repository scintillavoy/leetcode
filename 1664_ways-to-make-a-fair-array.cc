#include <vector>
using namespace std;

class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        vector<int> sum(2, 0);
        for (int i = 0; i < nums.size(); ++i) {
            sum[i%2] += nums[i];
        }
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum[i%2] -= nums[i];
            if (sum[0] == sum[1]) {
                ++count;
            }
            sum[(i+1)%2] += nums[i];
        }
        return count;
    }
};

int main() {
    return 0;
}
