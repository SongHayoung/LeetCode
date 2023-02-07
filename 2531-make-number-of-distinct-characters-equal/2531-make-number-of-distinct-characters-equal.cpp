class Solution {
    bool check(vector<int>& A, vector<int>& B) {
        int cnt = 0;
        for(int i = 0; i < 26; i++) {
            if(A[i]) cnt += 1;
            if(B[i]) cnt -= 1;
        }
        return cnt == 0;
    }
public:
    bool isItPossible(string word1, string word2) {
        vector<int> freq1(26), freq2(26);
        for(auto w : word1) freq1[w-'a'] += 1;
        for(auto w : word2) freq2[w-'a'] += 1;
        for(int i = 0; i < 26; i++) {
            if(!freq1[i]) continue;
            for(int j = 0; j < 26; j++) {
                if(!freq2[j]) continue;
                freq1[i] -= 1;
                freq2[j] -= 1;
                freq1[j] += 1;
                freq2[i] += 1;
                if(check(freq1,freq2)) return true;
                freq1[i] += 1;
                freq2[j] += 1;
                freq1[j] -= 1;
                freq2[i] -= 1;
            }
        }
        return false;
    }
};