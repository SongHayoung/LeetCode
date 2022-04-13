class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int res = 0, ma = -1;
        for(int i = 0; i < arr.size(); i++) {
            ma = max(ma, arr[i]);
            if(i == ma)
                res++;
        }
        return res;
    }
};