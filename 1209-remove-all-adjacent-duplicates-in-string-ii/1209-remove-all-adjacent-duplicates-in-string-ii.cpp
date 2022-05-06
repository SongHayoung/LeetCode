class Solution {
    int isDuplicate(list<char> &l, int k) {
        if (l.size() < k) return l.size();
        auto it = l.begin();
        int i = k;
        while (i--) {
            if (*it != l.front()) return k - i - 1;
            it++;
        }
        return -1;
    }

    void __pop_front(list<char> &l, int k) {
        auto to = l.begin(); advance(to, k);
        l.erase(l.begin(), to);
    }

    void __push_front(list<char> &from, list<char> &to, int k) {
        while (k-- && from.size()) {
            to.push_front(from.back());
            from.pop_back();
        }
    }

    void __push_back(list<char>& from, list<char>& to, int k) {
        while(k-- && from.size()) {
            to.push_back(from.front());
            from.pop_front();
        }
    }

public:
    string removeDuplicates(string s, int k) {
        list<char> res, ss(begin(s), end(s));
        while (ss.size()) {
            int dup = isDuplicate(ss, k);
            if (dup == -1) {
                __pop_front(ss, k);
                __push_front(res, ss, k);
            } else {
                __push_back(ss, res, dup);
            }
        }
        return string(res.begin(), res.end());
    }
};