class SnakeGame {
    const int dx[4] = {0, 1, 0, -1};
    const int dy[4] = {-1, 0, 1, 0};
    map<string, int> m;
    int score;
    int h;
    int w;
    queue<vector<int>> q;
    list<pair<int,int>> pos;
    set<pair<int,int>> s;
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<vector<int>>& food) : w(width), h(height), score(0) {
        for(auto& f : food) {
            q.push(f);
        }
        m.insert({"U", 0});
        m.insert({"R", 1});
        m.insert({"D", 2});
        m.insert({"L", 3});
        pos.push_front({0, 0});
        s.insert({0,0});
    }

    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
        @return The game's score after the move. Return -1 if game over.
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        if(!inRange(pos.front().first, pos.front().second))  return -1;
        pair<int, int> npos = {pos.front().first + dy[m[direction]], pos.front().second + dx[m[direction]]};
        pair<int, int> tail = pos.back();
        pos.pop_back();
        s.erase(tail);
        if(!inRange(npos.first, npos.second))  return -1;
        if(!q.empty() && q.front().front() == npos.first && q.front().back() == npos.second) {
            pos.push_back(tail);
            s.insert(tail);
            q.pop();
            score++;
        }
        pos.push_front(npos);
        if(s.count(npos)) {
            pos.front().first = pos.front().second = -1;
            return -1;
        } else s.insert(npos);

        return score;
    }

    bool inRange(int y, int x) {
        return 0 <= x && x < w && 0 <= y && y < h;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */
