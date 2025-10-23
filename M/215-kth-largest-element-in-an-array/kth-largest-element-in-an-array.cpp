class Solution {
public:
    int binarySearch(vector<int>& nums, int k) {
        int current_element = nums[nums.size() / 2];
        std::vector<int> tail = {};
        std::vector<int> head = {};
        int duplicates = 0;
        for (auto& elem : nums) {
            if (elem > current_element) {
                head.push_back(elem);
            }
            else if (elem == current_element) {
                duplicates++;
            }
            else if (elem < current_element) {
                tail.push_back(elem);
            }
        }
        if ((k <= head.size() + duplicates) && (k > head.size()))
            return current_element;
        if (head.size() >= k) {
            return binarySearch(head, k);
        }
        return binarySearch(tail, k - (head.size() + duplicates));
    }
    int findKthLargest(vector<int>& nums, int k) {
        return binarySearch(nums, k);
    }
};