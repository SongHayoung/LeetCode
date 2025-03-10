class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        unordered_map<char, int> vowel_count;
        int n = word.length();
        int consonant_count = 0;
        int left = 0;
        long long result = 0;
        
        for (int right = 0; right < n; ++right) {
            char right_char = word[right];

            // Add the current character to the window
            if (vowels.count(right_char)) {
                vowel_count[right_char]++;
            } else {
                consonant_count++;
            }

            // Shrink the window from the left if consonants exceed k
            while (consonant_count > k) {
                char left_char = word[left];
                if (vowels.count(left_char)) {
                    vowel_count[left_char]--;
                    if (vowel_count[left_char] == 0) {
                        vowel_count.erase(left_char);
                    }
                } else {
                    consonant_count--;
                }
                left++;
            }

            // Check if we have all vowels and exactly k consonants
            if (vowel_count.size() == 5 && consonant_count == k) {
                // Since all substrings ending at 'right' and starting from 'left' to 'right'
                // are valid, we add the number of such substrings to the result
                result += (left + 1);
            }
        }

        return result;
    }
};