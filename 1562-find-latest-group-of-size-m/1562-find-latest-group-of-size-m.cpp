class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        vector<int> fl(arr.size() + 2);
        vector<int> cnt(arr.size() + 1);
        int res = -1;
        for(int i = 0; i < arr.size(); i++) {
            fl[arr[i]] = 1;
            int le = fl[arr[i] - 1], ri = fl[arr[i]+1], len = le + ri + 1;
            cnt[le]--, cnt[ri]--;
            cnt[len]++;
            fl[arr[i]-le] = fl[arr[i]+ri] = len;
            if(cnt[m]) res = i + 1;
        }
        return res;
    }
};