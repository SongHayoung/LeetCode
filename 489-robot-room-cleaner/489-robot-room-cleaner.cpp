/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (std::pair<T1, T2> const &pair) const {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};

class Solution {
    unordered_set<std::pair<int, int>, pair_hash> p;
    int dx[4]{0, 1, 0, -1}, dy[4]{-1, 0, 1, 0};
    void dfs(Robot& r, int y = 0, int x = 0, int dir = 0) {
        p.insert({y, x});
        r.clean();
        for(int i = 0; i < 4; i++) {
            if(p.count({y + dy[dir], x + dx[dir]})) {
                r.turnRight();
            } else if(r.move()) {
                dfs(r, y + dy[dir], x + dx[dir], dir);
                r.turnLeft();
            } else {
                r.turnRight();
            }
            dir = (dir + 1) % 4;
        }
        r.turnLeft();
        r.turnLeft();
        r.move();
    }
public:
    void cleanRoom(Robot& robot) {
        dfs(robot);
    }
};