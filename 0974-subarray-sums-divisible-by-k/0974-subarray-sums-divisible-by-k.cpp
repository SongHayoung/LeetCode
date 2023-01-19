class Solution {
public:
    int subarraysDivByK(vector<int>& A, int k) {
        int res = 0, sum = 0;
        unordered_map<int, int> freq{{0, 1}};
        for(auto& a : A) {
            sum = (sum + (a % k) + k) % k;
            res += freq[sum];
            freq[sum]++;
        }
        return res;
    }
};