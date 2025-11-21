class Solution {
public:
    int maxTransactions(vector<int>& transactions) {
        long long skip = 0, balance = 0;
        priority_queue<int, vector<int>, greater<>> q;
        for(auto& t : transactions) {
            if(t < 0) q.push(t);
            balance += t;
            if(balance < 0) {
                skip++;
                balance -= q.top(); q.pop();
            }
        }
        
        return transactions.size() - skip;
    }
};
