class Solution {
public:
    int totalMoney(int n) {
        int money_per_week = 28;
        int count_of_weeks = int(n /7);
        int count_of_days = int(n%7);
        int money = 0;
        std::cout << count_of_weeks << " " << std::endl;
        for (int i = 0; i< count_of_weeks; i++){
            money +=money_per_week;
            money_per_week +=7;
        }
        for (int i =1; i<=count_of_days; i++ ){
            money+=count_of_weeks+i;
        }
        return money;
    }
};