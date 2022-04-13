class Solution {
public:
    bool isRobotBounded(string instructions) {
        int dir = 1, dx[4] {0, 1, 0, -1}, dy[4] {-1,0,1,0};
        pair<int, int> p{0, 0};
        for(auto& c : instructions) {
            switch (c) {
                case 'G': p.first += dy[dir], p.second += dx[dir]; break;
                case 'L' : dir = (dir + 3) % 4; break;
                case 'R' : dir = (dir + 1) % 4; break;
            }
        }

        return !p.first && !p.second || dir != 1;
    }
};