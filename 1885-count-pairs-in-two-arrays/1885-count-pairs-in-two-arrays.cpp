class Solution {
    int fenwick[200001];
    void update(int n) {
        while(n < 200001) {
            fenwick[n] += 1;
            n += n & -n;
        }
    }
    int qry(int n) {
        int res = 0;
        while(n > 0) {
            res += fenwick[n];
            n -= n & -n;
        }
        return res;
    }
public:
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {
        long long res = 0, n = nums1.size();
        for(int i = 0; i < n; i++) {
            res += qry(2 * 1e5) - qry(nums2[i] - nums1[i] + 1e5);
            update(nums1[i] - nums2[i] + 1e5);
        }
        return res;
    }
};