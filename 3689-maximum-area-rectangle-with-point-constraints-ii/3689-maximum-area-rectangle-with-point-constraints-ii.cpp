#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

struct PairHash {
    inline size_t operator()(const pair<long long, long long> &v) const { 
        return hash<long long>()(v.first) ^ (hash<long long>()(v.second) << 1);
    }
};

struct Seg {
    long long mi, ma, best;
    Seg *left, *right;

    Seg(vector<long long>& A, long long l, long long r): mi(A[l]), ma(A[r]), best(-1e18), left(nullptr), right(nullptr) {
        if (l != r) {
            long long m = l + (r - l) / 2;
            left = new Seg(A, l, m);
            right = new Seg(A, m + 1, r);
        }
    }

    long long query(long long l, long long r) {
        if (l <= mi && ma <= r) return best;
        if (l > ma || r < mi) return -1e18;
        return max(left->query(l, r), right->query(l, r));
    }

    void update(long long n, long long x) {
        if (mi <= n && n <= ma) {
            best = max(best, x);
            if (left) left->update(n, x);
            if (right) right->update(n, x);
        }
    }
};

class Solution {
public:
    long long maxRectangleArea(vector<int>& xCoord, vector<int>& yCoord) {
        vector<vector<int>> points;
        for(int i = 0; i < xCoord.size(); i++) points.push_back({xCoord[i], yCoord[i]});
        unordered_map<long long, vector<long long>> rows;
        for (auto& p : points) {
            rows[p[0]].push_back(p[1]);
        }

        unordered_map<pair<long long, long long>, vector<long long>, PairHash> lines;
        for (auto& row : rows) {
            vector<long long>& xs = row.second;
            sort(xs.begin(), xs.end());
            for (size_t i = 0; i + 1 < xs.size(); i++) {
                lines[{xs[i], xs[i + 1]}].push_back(row.first);
            }
        }

        priority_queue<array<long long, 4>, vector<array<long long, 4>>, greater<array<long long, 4>>> q;
        for (auto& line : lines) {
            vector<long long>& ys = line.second;
            sort(ys.begin(), ys.end());
            for (int i = 0; i < ys.size(); i++) {
                q.push({ys[i], line.first.first, line.first.second, i});
            }
        }

        vector<long long> x;
        for (auto& p : points) x.push_back(p[1]);
        sort(x.begin(), x.end());
        x.erase(unique(x.begin(), x.end()), x.end());

        Seg* seg = new Seg(x, 0, x.size() - 1);
        long long res = -1;
        sort(points.rbegin(), points.rend());

        while (!q.empty()) {
            auto [y, x0, x1, idx] = q.top();
            q.pop();

            while (!points.empty() && (points.back()[0] < y or (points.back()[0] == y and points.back()[1] < x0))) {
                seg->update(points.back()[1], points.back()[0]);
                points.pop_back();
            }
            

            if (idx) {
                long long ma = seg->query(x0, x1);
                long long py = lines[{x0, x1}][idx - 1];
                if (ma == py) res = max(res, (y - py) * (x1 - x0));
            }
        }

        return res;
    }
};