class Solution {
     static inline std::vector<std::string> BEAUTIFUL_NUMBERS = {
        "1",     "22",    "122",    "333",    "1333",   "4444",   "14444",
        "22333", "55555", "122333", "155555", "224444", "666666", "1224444"};

public:
    int nextBeautifulNumber(int n) {
        if (n > 666666) return 1224444;
        int result;
        int answer = 1224444;
        size_t current_size = 1;
        for (auto& beautifule_number : BEAUTIFUL_NUMBERS) {
            std::string number_combination = beautifule_number;
            if (current_size < beautifule_number.size() && answer < 1224444)
                return answer;
            current_size = beautifule_number.size();
            do {
                std::from_chars(number_combination.data(),
                                number_combination.data() +
                                    number_combination.size(),
                                result);
                if (result > n && result < answer) answer = result;

            } while (std::next_permutation(number_combination.begin(),
                                           number_combination.end()));
        }
        return answer;
    }
};