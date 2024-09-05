
class Solution {
public:
    long long maxArea(int height, vector<int>& positions, string directions) {
        long long res = 0, now = 0, cnt = 0;
        vector<int> A(2 * height + 1);
        for(int i = 0; i < positions.size(); i++) {
            now += positions[i];
            if(positions[i] == 0) directions[i] = 'U';
            if(positions[i] == height) directions[i] = 'D';
            if(directions[i] == 'U') {
                int mi = height - positions[i];
                A[mi] -= 1;
                A[mi+height] += 1;
                cnt++;
            } else {
                A[positions[i]] += 1;
                A[positions[i] + height] -= 1;
            }
        }
        res = max(res, now);
        for(int i = 0; i <= 2 * height; i++) {
            cnt += A[i];
            now = now + cnt - (positions.size() - cnt);
            res = max(res, now);
        }
        return res;
    }
};