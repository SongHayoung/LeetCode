class DetectSquares {
    int p[1001][1001];
    bool valid(pair<int,int> p) {
        return 0 <= p.first and p.first <= 1000 and 0 <= p.second and p.second <= 1000;
    }
    int get(pair<int,int> p1,pair<int,int> p2,pair<int,int> p3,pair<int,int> p4) {
        if(!valid(p1)) return 0;
        if(!valid(p2)) return 0;
        if(!valid(p2)) return 0;
        if(!valid(p3)) return 0;
        
        return p[p2.first][p2.second] * p[p3.first][p3.second] * p[p4.first][p4.second];
    }
public:
    DetectSquares() {
        memset(p, 0, sizeof p);
    }
    
    void add(vector<int> point) {
        p[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int res = 0, y = point[0], x = point[1];
        for(int distance = 1; distance <= 1000; distance++) {
            res += get({y,x}, {y+distance,x-distance}, {y+distance,x}, {y,x-distance});
            res += get({y,x}, {y+distance,x+distance}, {y+distance,x}, {y,x+distance});
            res += get({y,x}, {y-distance,x-distance}, {y-distance,x}, {y,x-distance});
            res += get({y,x}, {y-distance,x+distance}, {y-distance,x}, {y,x+distance});
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