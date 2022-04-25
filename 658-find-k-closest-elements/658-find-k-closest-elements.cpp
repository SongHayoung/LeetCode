class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int r = lower_bound(begin(arr), end(arr), x) - begin(arr), l = r - 1;
        vector<int> res;
        while(k--) {
            if(l == -1) res.push_back(arr[r++]);
            else if(r == arr.size()) res.push_back(arr[l--]);
            else {
                if(abs(arr[r] - x) < abs(arr[l] - x)) res.push_back(arr[r++]);
                else res.push_back(arr[l--]);
            }
        }
        sort(begin(res), end(res));
        return res;
    }
};