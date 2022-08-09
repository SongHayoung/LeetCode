class Solution {
public:
    long long countVowels(string word) {
        long long res = 0, n = word.size();
        unordered_set<char> vowel = {'a','e','i','o','u'};
        for(int i = 0; i < n; i++) {
            if(vowel.count(word[i])) res += (i + 1) * (n - i);
        }
        return res;
    }
};