class Solution {
    bool canSwap(char a, char b) {
        if(a == 'X') return b == 'L';
        else return a == 'R' and b == 'X';
    }
public:
    bool canTransform(string start, string end) {
        for(int i = 0; i < start.length(); i++) {
            if(start[i] == end[i]) continue;
            auto pos = start.find(end[i], i);
            if(pos == string::npos) return false;
            for(int j = pos; j > i; j--) {
                if(canSwap(start[j-1], start[j])) {
                    swap(start[j], start[j-1]);
                } else return false;
            }

        }
        return true;
    }
};