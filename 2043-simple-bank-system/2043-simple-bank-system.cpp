class Bank {
    vector<long long> balance;
    bool validAccount(int account) {
        return account - 1 < balance.size();
    }
public:
    Bank(vector<long long>& balance) : balance(balance) {
        
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(!validAccount(account1) or !validAccount(account2)) return false;
        return withdraw(account1, money) and deposit(account2, money);
    }
    
    bool deposit(int account, long long money) {
        if(!validAccount(account)) return false;
        balance[account - 1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(!validAccount(account) or balance[account - 1] < money) return false;
        balance[account - 1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */