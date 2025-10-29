class Solution {
public:
    int smallestNumber(int n) {
        return (n>1) ? pow(2, std::ceil(std::log2(n+1)))-1 : 1;
    }
};