class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        long long n = word.length(), res = 0;
        unordered_set<char> vowels{'a','e','i','o','u'};
        unordered_map<char,int> freq;
        for(int i = 0, j = 0, cnt = 0; i < n; i++) {
            while(j < n and (freq.size() != 5 or cnt < k)) {
                if(vowels.count(word[j])) freq[word[j]]++;
                else cnt++;
                j++;
            }
            if(freq.size() == 5 and cnt == k) {
                res += 1;
                for(int k = j; k < word.length() and vowels.count(word[k]); k++) res++;
            }
            if(vowels.count(word[i])) {
                if(--freq[word[i]] == 0) freq.erase(word[i]);
            } else cnt--;
        }
        return res;
    }
};