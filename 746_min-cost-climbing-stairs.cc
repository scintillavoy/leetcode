#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev = cost[0];
        int curr = cost[1];
        for (vector<int>::size_type i = 2; i < cost.size(); ++i) {
            int temp = prev;
            prev = curr;
            curr = min(temp, prev) + cost[i];
        }
        return min(prev, curr);
    }
};

int main() {
    return 0;
}
