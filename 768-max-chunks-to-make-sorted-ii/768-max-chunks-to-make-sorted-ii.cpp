class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        unordered_map<int, int> counter;
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());
        int res = 0, n = arr.size();
        
        for(int i = 0; i < n; i++) {
            if(++counter[arr[i]] == 0)
                counter.erase(arr[i]);
            if(--counter[sorted[i]] == 0)
                counter.erase(sorted[i]);
            
            if(counter.empty())
                res++;
        }
        
        return res;
    }
};