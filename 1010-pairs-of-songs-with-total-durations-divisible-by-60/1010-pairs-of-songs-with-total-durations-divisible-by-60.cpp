class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> lookup;
        int res = 0;
        for(auto t : time) {
            int key = t % 60;
            res += lookup[(60 - key) % 60];
            lookup[key]++;
        }
        return res;
    }
};