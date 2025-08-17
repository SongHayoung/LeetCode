class Solution {
public:
    int minSensors(int n, int m, int k) {
        int cover = 2 * k + 1;
        int row = (n + cover - 1) / cover;
        int col = (m + cover - 1) / cover;
        return row * col;
    }
};