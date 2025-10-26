class Bank {
    vector<long long> A;
public:
    Bank(vector<long long>& balance): A(balance) {
        
    }
    bool checkAccount(int x) {
        return 0 <= x and x < A.size();
    }
    bool transfer(int account1, int account2, long long money) {
        account1 -= 1, account2 -= 1;
        if(!checkAccount(account1) or !checkAccount(account2)) return false;
        if(A[account1] < money) return false;
        A[account1] -= money;
        A[account2] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        account -= 1;
        if(!checkAccount(account)) return false;
        A[account] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        account -= 1;
        if(!checkAccount(account)) return false;
        if(A[account] < money) return false;
        A[account] -= money;
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