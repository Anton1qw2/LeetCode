class Solution {
public:
    int totalMoney(int n) {
        const auto [count_of_weeks, count_of_days] = std::div(n, 7);
        int money_per_week = 28;
        int money = 0;
        //Sₙ = n/2 × (2a₁ + (n-1)×d)
        money = count_of_weeks *
                (2 * money_per_week + (count_of_weeks - 1) * 7) / 2;
        money += count_of_days *
                 (2 * (count_of_weeks + 1) + (count_of_days - 1)) / 2;

        return money;
    }
};