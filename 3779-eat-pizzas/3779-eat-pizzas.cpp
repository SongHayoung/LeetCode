class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        int n = pizzas.size(), day = n / 4, even = day / 2, odd = day - even;
        sort(begin(pizzas), end(pizzas));
        long long res = 0;
        for(int i = 0; i < odd; i++) res += pizzas[n-i-1];
        for(int i = odd + day * 2; i < n - odd; i += 2) res += pizzas[i];
        return res;
    }
};