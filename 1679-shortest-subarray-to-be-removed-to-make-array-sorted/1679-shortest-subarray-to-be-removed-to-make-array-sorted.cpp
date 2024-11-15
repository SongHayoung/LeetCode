class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int res = arr.size() - 1, last;
        map<int, int> increase;
        for(last = 0; last < arr.size() - 1; last++) {
            increase[arr[last]] = last;
            if(arr[last] > arr[last + 1])
                break;
            res--;
        }
        
        for(int i = arr.size() - 1; i > last; --i) {
            auto it = increase.lower_bound(arr[i]);
            if(it->first == arr[i]) {
                res = min(res, i - it->second - 1);
            } else if(it == begin(increase)) {
                res = min(res, i);
            } else {
                res = min(res, i - prev(it)->second - 1);
            }
            
            if(arr[i] < arr[i - 1])
                break;
        }

        return res;
    }
};
