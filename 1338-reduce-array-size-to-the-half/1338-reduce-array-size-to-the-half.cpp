class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> freq;
        for(auto& a : arr) freq[a]++;
        int n = arr.size(), rm = 0, res = 0;
        priority_queue<int> q;
        for(auto& [_, f] : freq) q.push(f);
        while(!q.empty() and rm * 2 < n) {
            rm += q.top(); q.pop();
            res++;
        }
        return res;
    }
};