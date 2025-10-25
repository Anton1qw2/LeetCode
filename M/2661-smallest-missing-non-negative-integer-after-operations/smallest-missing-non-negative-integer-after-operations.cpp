#include <ranges>
class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        std::vector<uint32_t> divided_nums(value, 0);
        auto residues = nums | std::views::transform([value](int elem) {
                            return ((elem % value) + value) % value;
                        });
        for (auto key : residues)
            divided_nums[key]++;
        auto min_element = std::ranges::min_element(divided_nums);
        int min_index = std::distance(divided_nums.begin(), min_element);
        return static_cast<int>(value * *min_element + min_index);
    }
};