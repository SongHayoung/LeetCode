class Solution {
    int fenwick[20001];
    void update(int index) {
        while(index <= 20000) {
            fenwick[index]++;
            index += index & -index;
        }
    }
    int qry(int index) {
        int res = 0;
        while(index > 0) {
            res += fenwick[index];
            index -= index & -index;
        }
        return res;
    }
    bool verify(int from, int to) {
        int on = qry(from) - qry(from - 1);
        if(on == 0) return false;
        on = qry(to) - qry(to - 1);
        if(on == 0) return false;
        return qry(to - 1) == qry(from);
    }
public:
    int kEmptySlots(vector<int>& bulb, int k) {
        for(int i = 0; i < bulb.size(); i++) {
            update(bulb[i]);
            if(bulb[i] - k - 1 >= 1) { //check front
                if(verify(bulb[i] - k - 1, bulb[i]))
                    return i + 1;
            }
            if(bulb[i] + k + 1 <= bulb.size()) {
                if(verify(bulb[i], bulb[i] + k + 1))
                    return i + 1;
            }
        }
        return -1;
    }
};