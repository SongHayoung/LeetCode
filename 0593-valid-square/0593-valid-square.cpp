class Solution {
    int calc(vector<int>& A, vector<int>& B) {
        return (A[0] - B[0]) * (A[0] - B[0])  + (A[1] - B[1]) * (A[1] - B[1]);
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        map<int,int> mp;
        mp[calc(p1,p2)]++;
        mp[calc(p1,p3)]++;
        mp[calc(p1,p4)]++;
        mp[calc(p2,p3)]++;
        mp[calc(p2,p4)]++;
        mp[calc(p3,p4)]++;
        return mp.size() == 2 and begin(mp)->second == 4;
    }
};