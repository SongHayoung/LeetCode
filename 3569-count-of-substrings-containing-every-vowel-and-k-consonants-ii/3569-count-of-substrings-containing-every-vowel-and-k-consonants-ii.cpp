class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        long long n = word.length(), res = 0;
        unordered_set<char> vowels{'a','e','i','o','u'};
        vector<int> suf(n + 1);
        for(int i = n - 1; i >= 0; i--) {
            if(i + 1 < n and vowels.count(word[i+1])) suf[i] = suf[i+1] + 1;
            else suf[i] = vowels.count(word[i]);
        }
        unordered_map<char,int> freq;
        for(int i = 0, j = 0, cnt = 0; i < n; i++) {
            while(j < n and (freq.size() != 5 or cnt < k)) {
                if(vowels.count(word[j])) freq[word[j]]++;
                else cnt++;
                j++;
            }
            if(freq.size() == 5 and cnt == k) {
                res += max(1, suf[j-1]);
            }
            if(vowels.count(word[i])) {
                if(--freq[word[i]] == 0) freq.erase(word[i]);
            } else cnt--;
        }
        return res;
    }
};