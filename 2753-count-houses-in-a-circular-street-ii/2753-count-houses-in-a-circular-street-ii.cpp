/**
 * Definition for a street.
 * class Street {
 * public:
 *     Street(vector<int> doors);
 *     void closeDoor();
 *     bool isDoorOpen();
 *     void moveRight();
 * };
 */
class Solution {
public:
    int houseCount(Street* street, int k) {
        vector<int> o(2 * k), p(2 * k);
        for(int i = 0; i < 2 * k; i++) {
            o[i] = street->isDoorOpen();
            street->moveRight();
        }
        while(!street->isDoorOpen()) street->moveRight();
        street->closeDoor();
        street->moveRight();
        for(int i = 0; i < 2 * k; i++) {
            p[i] = street->isDoorOpen();
            street->moveRight();
        }
        vector<int> PI(2 * k);
        for(int i = 1, j = 0; i < p.size(); i++) {
            while(j and p[i] != p[j]) j = PI[j-1];
            if(p[i] == p[j]) PI[i] = ++j;
        }
        int res = 0;
        for(int i = 0, j = 0; i < p.size(); i++) {
            while(j and o[i] != p[j]) j = PI[j-1];
            if(o[i] == p[j]) {
                j += 1;
                res = max(res, j);
                if(j == p.size()) j = PI[j-1];
            }
        }
        return res + 1;
    }
};