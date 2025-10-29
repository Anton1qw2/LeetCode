class Solution {
public:
    int smallestNumber(int n) {
        return pow(2, std::ceil(std::log2(n + 1))) - 1;
    }
};