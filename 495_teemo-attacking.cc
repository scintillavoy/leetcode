/* Never underestimate the power of the scout's code */

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.empty()) return 0;
        int total_time = duration;
        for (int i = 1; i < timeSeries.size(); ++i) {
            total_time -= max(duration - timeSeries[i] + timeSeries[i-1], 0);
            total_time += duration;
        }
        return total_time;
    }
};

int main() {
    return 0;
}
