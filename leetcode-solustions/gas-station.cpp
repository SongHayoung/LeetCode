class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size(gas.size()), sum(0), subsum(INT_MAX), res(0);
        for(int i = 0; i < size; i++) {
            sum += gas[i] - cost[i];
            if(subsum > sum) subsum = sum, res = i;
        }

        return sum < 0 ? -1 : ++res % size;
    }
};
