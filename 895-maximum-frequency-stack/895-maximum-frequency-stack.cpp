class FreqStack {
    unordered_map<int, list<int>> m;
    map<int, list<int>> sizeMap;
    int cnt = 0;
public:
    FreqStack() {
    }
    void push(int x) {
        m[x].push_back(cnt++);
        sizeMap[(int)m[x].size()].push_back(x);
    }

    int pop() {
        auto res = prev(end(sizeMap))->second.back();
        sizeMap[(int)m[res].size()].pop_back();
        if(sizeMap[(int)m[res].size()].empty())
            sizeMap.erase((int)m[res].size());
        m[res].pop_back();
        return res;
    }
};