class Solution {
    bool ok(vector<int>& A, vector<int>& B) {
        for(int i = 0; i < 26; i++) {
            if(A[i] < B[i]) return false;
        }
        return true;
    }
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> freq(26);
        for(auto& ch : chars) freq[ch-'a'] += 1;
        int res = 0;
        for(auto& w : words) {
            vector<int> now(26);
            for(auto& ch : w) now[ch-'a'] += 1;
            if(ok(freq,now)) res += w.size();
        }
        return res;
    }
};