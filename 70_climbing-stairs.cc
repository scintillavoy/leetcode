/**
 * This solution has the time complexity O(n)
 * O(lgn) can be achieved by using matrix multiplication
 * F(n)     F(n-1)      1   1
 * F(n-1)   F(n-2)      1   0
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int prev = 1;
        int curr = 1;
        for (int i = 2; i <= n; ++i) {
            int temp = prev;
            prev = curr;
            curr = temp + prev;
        }
        return curr;
    }
};

int main() {
    Solution sol;
    for (int i = 1; i <= 45; ++i) {
        cout << "climbStairs(" << i << "): " << sol.climbStairs(i) << endl;
    }
    return 0;
}
