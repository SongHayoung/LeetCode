class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        vector<pair<int, int>> A;
        int n = values.size(), res = 0;
        for(int i = 0; i < n; i++) {
            A.push_back({values[i], labels[i]});
        }
        sort(rbegin(A), rend(A));
        unordered_map<int, int> freq;
        for(int i = 0; i < n and numWanted; i++) {
            auto [v, l] = A[i];
            if(freq[l] == useLimit) continue;
            res += v;
            ++freq[l];
            --numWanted;
        }
        return res;
    }
};