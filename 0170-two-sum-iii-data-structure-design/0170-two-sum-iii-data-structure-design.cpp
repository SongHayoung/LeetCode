class TwoSum {
    bitset<202020> bit, sum;
    int gap = 1e5;
public:
    TwoSum() {}
    
    void add(int number) {
        if(number > 0) sum |= bit<<number;
        else if(number == 0) sum |= bit;
        else sum |= bit>>(-number);
        bit[number + gap] = 1;
    }

    bool find(int value) {
        long long x = 1ll * value + gap;
        if(x < 0 or x >= 202020) return false;
        return sum[x];
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */