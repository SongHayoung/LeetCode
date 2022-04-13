class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        n = n % 14;
        if(!n) n = 14;
        while(n--) {
            vector<int> next(8,0);

            for(int i = 1; i <= 6; i++) {
                if(cells[i-1] == cells[i + 1])
                    next[i] = 1;
            }
            
            cells.swap(next);
        }
        return cells;
    }
};