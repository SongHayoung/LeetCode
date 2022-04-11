class Solution {
private:
    vector<vector<char>> digits = {{},{},{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},
                                   {'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
    vector<string> addChar(int digit, vector<string> solution) {
        vector<string> res;
        res.reserve(solution.size() * digits[digit].size());

        for(char alpha : digits[digit]) {
            for(string letter : solution) {
                res.push_back(alpha + letter);
            }
        }

        return res;
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> solution;
        if(digits == "")
            return solution;
        
        solution.push_back("");
        for(int i = digits.length() - 1; i >= 0; i--) {
            solution = addChar(digits[i] & 0b1111, solution);
        }

        return solution;
    }
};
