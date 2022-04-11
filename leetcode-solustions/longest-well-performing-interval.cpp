class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int res = 0;
        int sum = 0;
        unordered_map<int, int> table;
        for(int i = 0; i < hours.size(); i++) {
            sum += (hours[i] >= 9 ? 1 : -1);
            if(sum > 0) {
                res = i + 1;
            } else {
                if(!table.count(sum))
                    table[sum] = i;

                if(table.count(sum - 1))
                    res = max(res, i - table[sum - 1]);
            }
        }
        return res;
    }
};
