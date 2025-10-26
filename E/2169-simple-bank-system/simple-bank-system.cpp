class Bank {
private:
    vector<long long> user_balance;

public:
    Bank(vector<long long>& balance) {
        // Инициализируем со смещением в 1 элемент чтобы избежать возни с индексом аккаунта
        user_balance.reserve(balance.size() + 1);
        user_balance.push_back(0);
        user_balance.insert(user_balance.end(), balance.begin(), balance.end());
    }
    bool user_is_valid(int account) {
        return (account > 0) && (user_balance.size() > account);
    }
    bool transfer(int account1, int account2, long long money) {
        if (!user_is_valid(account1)) [[unlikely]]
            return false;
        if (!user_is_valid(account2)) [[unlikely]]
            return false;
        bool transaction = (user_balance[account1] >= money);

        if (transaction) {
            withdraw(account1, money);
            deposit(account2, money);
        }
        return transaction;
    }

    bool deposit(int account, long long money) {
        if (money < 0) [[unlikely]]
            return false;
        if (!user_is_valid(account)) [[unlikely]]
            return false;
        user_balance[account] += money;
        return true;
    }

    bool withdraw(int account, long long money) {
        if (money < 0) [[unlikely]]
            return false;
        if (!user_is_valid(account)) [[unlikely]]
            return false;
        bool transaction = (user_balance[account] >= money);
        if (transaction) {
            user_balance[account] += -money;
        }
        return transaction;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */