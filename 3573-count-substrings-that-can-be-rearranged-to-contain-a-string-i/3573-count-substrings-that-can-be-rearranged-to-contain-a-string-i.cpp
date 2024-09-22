#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();

        if (n2 > n1) return 0;

        unordered_map<char, int> targetFreq, windowFreq;
        for (char c : word2) {
            targetFreq[c]++;
        }

        long long count = 0;
        int left = 0;

        for (int right = 0; right < n1; ++right) {
            windowFreq[word1[right]]++;

            while (right - left + 1 > n2) {
                windowFreq[word1[left]]--;
                if (windowFreq[word1[left]] == 0) {
                    windowFreq.erase(word1[left]);
                }
                left++;
            }

            if (right - left + 1 >= n2 && isValidPrefix(windowFreq, targetFreq)) {
                count += (right - left + 1 - n2 + 1);
            }
        }

        return count;
    }

private:
    bool isValidPrefix(unordered_map<char, int>& windowFreq, unordered_map<char, int>& targetFreq) {
        for (auto& [key, value] : targetFreq) {
            if (windowFreq[key] < value) {
                return false;
            }
        }
        return true;
    }
};