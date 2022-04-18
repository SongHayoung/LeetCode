class ProductOfNumbers {
    long long zero = INT_MAX;
    deque<long long> prefixProduct {1ll};
public:
    ProductOfNumbers() {}

    void add(int num) {
        if(!num) {
            prefixProduct.clear();
            prefixProduct.push_back(1ll);
            zero = 1;
        } else {
            prefixProduct.push_back(num * prefixProduct.back());
            zero++;
        }
        if(prefixProduct.size() > 40001)
            prefixProduct.pop_front();
    }

    int getProduct(int k) {
        if(k >= zero) return 0;
        return prefixProduct.back() / prefixProduct[prefixProduct.size() - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
