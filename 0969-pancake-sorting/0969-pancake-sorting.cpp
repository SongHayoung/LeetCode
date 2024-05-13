class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        int n = arr.size();
        vector<int> res;
        unordered_map<int,int> at;
        for(int i = 0; i < n; i++) at[arr[i]] = i;
        auto filp = [&](int p) {
            int i = 0, j = p;
            while(i < j) {
                swap(arr[i], arr[j]);
                at[arr[i]] = i;
                at[arr[j]] = j;
                i++,j--;
            }
        };
        for(int i = n - 1; i; i--) {
            if(arr[i] == i + 1) continue;
            int pos = at[i+1];
            filp(pos);
            res.push_back(pos+1);
            filp(i);
            res.push_back(i+1);
        }
        return res;
    }
};