/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        std::sort(nums.begin(), nums.end());
        while (head->next &&
               std::binary_search(nums.begin(), nums.end(), head->val)) {
            head = head->next;
        }
        ListNode* current = head;
        while (current->next) {
            if (std::binary_search(nums.begin(), nums.end(),
                                   current->next->val)) {
                current->next = current->next->next;
            } else {
                current = current->next;
            }
        }
        return head;
    }
};