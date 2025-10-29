#include <ranges>
class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        auto zero_view = nums | std::views::enumerate |
                         std::views::filter([](const auto& enumerated) {
                             auto [index, value] = enumerated; // Декомпозиция
                             return value == 0;
                         }) |
                         std::views::transform([](const auto& enumerated) {
                             auto [index, value] = enumerated;
                             return index;
                         });
        int total_sum = std::accumulate(nums.begin(), nums.end(), 0);
        int result = 0;
        for (auto zero_index : zero_view) {
            const int left_sum =
                2 * std::accumulate(nums.begin(), nums.begin() + zero_index, 0);
            const int distance = abs(left_sum - total_sum);
            if (distance > 1)
                continue;
            result += (distance == 0) ? 2 : 1;
        }
        return result;
    }
};