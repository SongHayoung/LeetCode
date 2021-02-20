class Solution {
    struct myHash {
        template <class T1, class T2>
        size_t operator() (std::pair<T1, T2> const& pair) const {
            size_t h1 = hash<T1>()(pair.first);
            size_t h2 = hash<T2>()(pair.second);

            return h1 ^ h2;
        }
    };
public:
    bool isReflected(vector<vector<int>>& points) {
        unordered_set<pair<int, int>, myHash> hashSet;
        int maxVal{points[0][0]}, minVal{points[0][0]};
        for(auto& point : points) {
            hashSet.insert({point[0], point[1]});
            maxVal = max(maxVal, point[0]);
            minVal = min(minVal, point[0]);
        }
        
        int y = maxVal + minVal;
        
        for(auto& point : hashSet) {
            if(!hashSet.count({y - point.first, point.second}))
                return false;
        }
        return true;
    }
};
