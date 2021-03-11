#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curr_gas = 0;
        int max_gas = -1;
        int max_gas_idx = -1;
        for (int i = gas.size()-1; i >= 0; --i) {
            curr_gas += gas[i] - cost[i];
            if (curr_gas > max_gas) {
                max_gas = curr_gas;
                max_gas_idx = i;
            }
        }
        return (curr_gas >= 0 ? max_gas_idx : -1);
    }
};

int main() {
    return 0;
}
