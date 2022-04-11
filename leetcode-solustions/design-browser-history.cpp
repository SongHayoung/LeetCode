class BrowserHistory {
    vector<string> history;
    int cur;
    int last;
public:
    BrowserHistory(string homepage) : cur(0), last(0) {
        history.push_back(homepage);
    }

    void visit(string url) {
        if(cur == history.size() - 1) {
            history.push_back(url);
            cur++;
            last++;
        } else {
            history[last = ++cur] = url;
        }
    }

    string back(int steps) {
        cur = max(cur - steps, 0);
        return history[cur];
    }

    string forward(int steps) {
        cur = min(cur + steps, last);
        return history[cur];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
