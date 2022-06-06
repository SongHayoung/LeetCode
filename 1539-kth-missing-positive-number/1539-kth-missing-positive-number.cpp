class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if(arr[0] > k) return k;
        int l = 0, r = arr.size() - 1, res = INT_MAX, n = arr.size();
        
        while(l <= r) {
            int m = l + (r - l) / 2;
            if(m + 1 == n) {
                return arr[m] + k - (arr[m] - (m + 1));
            }
            
            
            int missing = arr[m] - (m + 1);
            int rmissing = arr[m + 1] - (m + 2);
            
            if(m == 0 and missing >= k) return k;
            
            if(missing < k and k <= rmissing) {
                return arr[m] + k - missing;
            }
            if(missing >= k) r = m - 1;
            else l = m + 1;
        }
        
        return res;
    }
};