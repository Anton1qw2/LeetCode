class Solution {
public:
    int totalMoney(int n) {
        const auto [count_of_weeks, count_of_days] = std::div(n, 7);
        int money_per_week = 28;
        int money = 0;
        for (int i = 0; i < count_of_weeks; i++) {
            money += money_per_week;
            money_per_week += 7;
        }

        for (int i = 1; i <= count_of_days; i++) {
            money += count_of_weeks + i;
        }
        return money;
    }
};