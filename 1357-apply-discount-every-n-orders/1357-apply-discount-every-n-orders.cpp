class Cashier {
    int c,x,d;
    unordered_map<int,long long> mp;
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        c = 0, x = n, d = discount;
        for(int i = 0; i < products.size(); i++) mp[products[i]] = prices[i];
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        double bill = 0;
        for(int i = 0; i < product.size(); i++) {
            bill += mp[product[i]] * amount[i];
        }
        if(++c == x) {
            bill = bill * ((100 - d) / 100.);
            c = 0;
        }
        return bill;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */