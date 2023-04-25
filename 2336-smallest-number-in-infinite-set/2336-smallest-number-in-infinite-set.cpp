class SmallestInfiniteSet {
    int mi = 1;
    set<int> st;
public:
    SmallestInfiniteSet() {}

    int popSmallest() {
        if(st.empty()) return mi++;
        int res = *begin(st);
        st.erase(begin(st));
        return res;
    }

    void addBack(int num) {
        if(mi <= num) return;
        st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */