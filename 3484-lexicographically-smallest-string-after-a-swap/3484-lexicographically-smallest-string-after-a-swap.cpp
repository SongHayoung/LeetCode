class Solution {
public:
    string getSmallestString(string s) {
           int n = s.size();
        bool swapped = false;
        
        for (int i = 0; i < n - 1; ++i) {
            if ((s[i] - '0') % 2 == (s[i + 1] - '0') % 2) { // Check if the parity is the same
                if (s[i] > s[i + 1]) { // Swap if it makes the string smaller
                    std::swap(s[i], s[i + 1]);
                    swapped = true;
                }
                if (swapped) break; // We can only swap once
            }
        }

        return s;
    }
};