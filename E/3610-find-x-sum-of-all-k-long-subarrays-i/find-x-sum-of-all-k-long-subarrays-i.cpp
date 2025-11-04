class Solution {
public:
    static const constexpr auto sort_perf_count = [](const auto& a,
                                                     const auto& b) {
        if (a.second == b.second)
            return a.first > b.first;
        return a.second > b.second;
    };

    static const constexpr auto sum_pair = [](int acc, const auto& pair) {
        return acc + pair.first * pair.second;
    };
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int result_size = nums.size() - k + 1;
        std::cout << result_size;
        std::vector<int> result(result_size, 0);
        for (int i = 0; i < result_size; i++) {
            std::vector<std::pair<int, int>> coordinates(k, {0, 0});
            for (int slice = i; slice < i + k; slice++) {
                for (auto& pair : coordinates) {
                    if (pair.first == nums[slice]) {
                        pair.second++;
                        break;
                    }
                    if (pair.second == 0) {
                        pair.first = nums[slice];
                        pair.second++;
                        break;
                    }
                }
            }
            std::sort(coordinates.begin(), coordinates.end(), sort_perf_count);
            result[i] = std::accumulate(coordinates.begin(),
                                        coordinates.begin() + x, 0, sum_pair);
        }
        return result;
    }
};