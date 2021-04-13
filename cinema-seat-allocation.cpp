class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int res = n << 1;
        const int left = 1, right = (1<<2), leftmid = left | (1<<1), rightmid = right | (1<<1);
        const int all = left | rightmid;
        unordered_map<int, short> m;
        
        for(auto& seat : reservedSeats) {
            switch (seat.back()) {
                case 2:
                case 3: m[seat.front()] |= left; break;
                case 4:
                case 5: m[seat.front()] |= leftmid; break;
                case 6:
                case 7: m[seat.front()] |= rightmid; break;
                case 8:
                case 9: m[seat.front()] |= right; break;
            }
        }

        for(auto& seat : m) {
            res -= seat.second ^ all ? 1 : 2;
        }

        return res;
    }
};
