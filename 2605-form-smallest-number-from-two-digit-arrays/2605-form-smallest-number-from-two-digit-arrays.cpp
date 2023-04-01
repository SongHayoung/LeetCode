class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> us1(begin(nums1), end(nums1)), us2(begin(nums2), end(nums2));
        int res = 100;
        for(int i = 1; i <= 9; i++) {
            if(!us1.count(i)) continue;
            for(int j = 1; j <= 9; j++) {
                if(!us2.count(j)) continue;
                if(i == j) res = min(res, j);
                else res = min({res, i * 10 + j, j * 10 + i});
            }
        }
        return res;
    }
};
