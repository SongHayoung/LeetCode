class Vector2D {
    vector<pair<vector<int>::iterator, vector<int>::iterator>> st;
    void move() {
        if((++st.back().first) == st.back().second) st.pop_back();
    }
public:
    Vector2D(vector<vector<int>>& vec) {
        for(int i = vec.size() - 1; i >= 0; i--) {
            if(!vec[i].empty())
                st.push_back({vec[i].begin(), vec[i].end()});
        }
    }

    int next() {
        int res = *st.back().first;
        move();
        return res;
    }

    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */