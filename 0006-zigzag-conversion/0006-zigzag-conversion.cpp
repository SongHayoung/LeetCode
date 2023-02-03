class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;

        stringstream solution;
        int firstGap = (numRows - 1) * 2, secondGap = 0;
        for(int i = 0; i < numRows; i++, firstGap -= 2, secondGap += 2) {
            for(int start = i; start < s.length();) {
                if(firstGap) {
                    solution<<s[start];
                    start += firstGap;
                }

                if(secondGap && start < s.length()) {
                    solution<<s[start];
                    start += secondGap;
                }
            }
        }
        return solution.str();
    }
};