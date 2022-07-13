class Cashier {
    unordered_map<int, int> mp;
    int n, dis;
    int cnt = 0;
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) : n(n), dis(discount) {
        for(int i = 0; i < products.size(); i++) {
            mp[products[i]] = prices[i];
        }
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        int sum = 0;
        for(int i = 0; i < product.size(); i++) {
            sum += mp[product[i]] * amount[i];
        }
        ++cnt;
        if(cnt % n) return sum;
        return sum * ((100-dis)/100.0);
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */