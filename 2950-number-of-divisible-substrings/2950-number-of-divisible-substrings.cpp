class Solution {
public:
    int countDivisibleSubstrings(string word) {
        vector<int> cost{1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,9,9,9};
        int res = 0;
        for(int i = 1; i <= 9; i++) {
            unordered_map<int,int> freq{{0,1}};
            int sum = 0;
            for(auto& ch : word) {
                int c = cost[ch-'a'];
                sum += c - i;
                res += freq[sum]++;
            }
        }
        return res;
    }
};