class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        std::vector<int> result(2, 0);
        int count_elements = 0;
        std::set<int> unique_numbers;
        for (auto& num : nums) {
            const int prev_size = unique_numbers.size();
            unique_numbers.insert(num);
            if (prev_size == unique_numbers.size()) {
                result[count_elements++] = num;
                // if (count_elements == 2)
                //     break;
            }
        }
        return result;
    }
};