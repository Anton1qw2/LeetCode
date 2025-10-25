/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // C++23:
    static constexpr auto find_first_number = [](char c) -> bool {
        return c != '-';
    };
    
    TreeNode* get_subtree(std::string_view& traversal, size_t depth) {
        //======================================================
        if (traversal.empty())
            return nullptr;
        size_t result = 0;
        // C++17: std::from_chars - низкоуровневый парсинг чисел
        auto [ptr, ec] = std::from_chars(
            traversal.begin(), traversal.begin() + traversal.size(), result);

        // C++20: [[unlikely]]
        if (ec != std::errc()) [[unlikely]]
            return nullptr;
        //======================================================

        TreeNode* subtree = new TreeNode(result);
        size_t number_length = std::distance(traversal.begin(), ptr);
        traversal = traversal.substr(number_length);

        auto process_child = [&](TreeNode*& child) {
            auto it = std::ranges::find_if(traversal, find_first_number);
            size_t distance = std::distance(traversal.begin(), it);
            if (distance == depth) {
                traversal = traversal.substr(distance);
                child = get_subtree(traversal, depth + 1);
            }
        };
        process_child(subtree->left);
        process_child(subtree->right);
        return subtree;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        // C++17: string_view
        std::string_view sv(traversal);
        return get_subtree(sv, 1);
    }
};