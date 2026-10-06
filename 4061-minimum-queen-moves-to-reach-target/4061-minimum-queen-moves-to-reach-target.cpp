
class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        if(source == target) return 0;
        if(source[0] == target[0] or source[1] == target[1]) return 1;
        if(abs(source[0] - target[0]) == abs(source[1] - target[1])) return 1;
        return 2;
    }
};