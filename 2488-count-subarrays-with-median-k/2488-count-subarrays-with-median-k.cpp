class Solution {
public:
    int countSubarrays(vector<int>& A, int k) {
        unordered_map<int, int> freq;
        int pos = find(begin(A), end(A), k) - begin(A), res = 0;
        for(int i = pos, now = 0; i < A.size(); i++) {
            if(A[i] < k) now -= 1;
            else if(A[i] > k) now += 1;
            freq[now] += 1;
        }
        for(int i = pos, now = 0; i >= 0; i--) {
            if(A[i] < k) now -= 1;
            else if(A[i] > k) now += 1;
            res += freq[-now] + freq[-now + 1];
        }
        return res;
    }
};