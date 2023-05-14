class Solution {
public:
    bool doesValidArrayExist(vector<int>& A) {
        return accumulate(begin(A), end(A), 0, bit_xor<void>()) == 0;
    }
};
