class ZigzagIterator {
    queue<pair<vector<int>::iterator, vector<int>::iterator>> q;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if(!v1.empty())
            q.push({v1.begin(), v1.end()});

        if(!v2.empty())
            q.push({v2.begin(), v2.end()});
    }

    int next() {
        int res = *q.front().first;
        if(q.front().first + 1 != q.front().second) {
            q.push({q.front().first + 1, q.front().second});
        }
        q.pop();
        return res;
    }

    bool hasNext() {
        return !q.empty();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */