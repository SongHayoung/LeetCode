class DetectSquares {
    set<int> yx[1001];
    int p[1001][1001] = {0,};
    int get(int y, int x) {
        if(0 <= y and y <= 1000 and 0 <= x and x <= 1000)
            return p[y][x];
        return 0;
    }
public:
    DetectSquares() {}
    
    void add(vector<int> point) {
        int y = point[0], x = point[1];
        p[y][x]++;
        yx[y].insert(x);
    }
    
    int count(vector<int> point) {
        int y = point[0], x = point[1], res = 0;
        for(auto& X : yx[y]) {
            int dis = x - X;
            if(dis == 0) continue;
            res += get(y+dis,X) * get(y,X) * get(y+dis,x);
            res += get(y-dis,X) * get(y,X) * get(y-dis,x);
        }
        return res;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */