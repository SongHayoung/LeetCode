class Solution {
    map<int, int> indexMap;
    void update(vector<long long>& fenwick, int index, int value) {
        while(index < fenwick.size()) {
            fenwick[index] += value;
            index = index + (index & -index);
        }
    }
    
    long long sum(vector<long long>& fenwick, int index) {
        long long result = 0;
        while(index > 0) {
            result += fenwick[index];
            index = index - (index & -index);
        }
        return result;
    }
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        for(int i = 0; i < nums1.size(); i++) {indexMap[nums1[i]] = i;}
        vector<long long> fenwickLeft(100003), fenwickRight(100003);
        vector<long long> sumLeft(nums1.size()), sumRight(nums1.size());
        for(int i = 0; i < nums2.size(); i++) {
            nums2[i] = indexMap[nums2[i]] + 1;
        }
        
        for(int i = 0; i < nums1.size(); i++) {
           sumLeft[i] = sum(fenwickLeft, nums2[i] - 1);
           update(fenwickLeft, nums2[i], 1);
        }
        
        for(int i = nums1.size() - 1; i >= 0; i--) {
            sumRight[i] = sum(fenwickRight, n) - sum(fenwickRight, nums2[i]);
            update(fenwickRight, nums2[i], 1);
        }
        
        long long res = 0;
        
        for(int i = 0; i < n; i++)
            res += sumLeft[i] * sumRight[i];
        
        return res;
    }
};