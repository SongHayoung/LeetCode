class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size(), res = -1;
        vector<int> merge(n + 2), count(n + 1);
        for(int i = 0; i < n; i++) {
            int a = arr[i], left = merge[a-1], right = merge[a+1];
            merge[a] = merge[a-left] = merge[a+right] = right + left + 1;
            count[left]--;
            count[right]--;
            count[merge[a]]++;
            if(count[m])
                res = i + 1;
        }
        return res;
    }
};