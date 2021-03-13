#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

#define MOD 1000000007

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_map<int, long long> dp;

        for (int i = 0; i < arr.size(); ++i) {
            long long num = 1;
            for (int j = 0; j < i; ++j) {
                if (arr[i] % arr[j] == 0 &&
                    dp.find(arr[i] / arr[j]) != dp.end()) {
                    num = (num + dp[arr[j]] * dp[arr[i] / arr[j]]) % MOD;
                }
            }
            dp.insert({arr[i], num});
        }

        int ans = 0;
        for (const auto &x : dp) {
            ans = (ans + x.second) % MOD;
        }
        return ans;
    }
};

int main() {
    return 0;
}
