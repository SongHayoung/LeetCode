class Solution {
public:
    vector<int> numOfBurgers(int A, int B) {
        if(B * 4ll < A or A & 1) return {};
        int jumbo = 0, small = B;
        A -= B * 2;
        if(A < 0 or A & 1) return {};
        jumbo += A / 2;
        small -= jumbo;
        return {jumbo, small};
    }
};