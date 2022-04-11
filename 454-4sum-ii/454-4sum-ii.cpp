class Solution {
    unordered_map<int, int> comb(vector<int>& n1, vector<int>& n2) {
        unordered_map<int, int> res;
        for(auto num1 : n1)
            for(auto num2 : n2)
                res[num1 + num2]++;
        return res;
    }
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> comb1 = comb(nums1, nums2);
        unordered_map<int,int> comb2 = comb(nums3, nums4);
        int res = 0;
        for(auto [k, v] : comb1)
            res += v * comb2[-k];
        return res;
    }
};