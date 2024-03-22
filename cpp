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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) {
            // An empty list or a list with a single node is a palindrome.
            return true;
        }

        // Step 1: Find the middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half of the linked list
        ListNode* secondHalf = slow->next;
        slow->next = nullptr; // Break the link

        ListNode* prev = nullptr;
        ListNode* current = secondHalf;
        ListNode* nextNode = nullptr;

        while (current) {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        secondHalf = prev;

        // Step 3: Compare the first half with the reversed second half
        ListNode* firstHalf = head;
        while (firstHalf && secondHalf) {
            if (firstHalf->val != secondHalf->val) {
                return false; // Not a palindrome
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        return true;
    }
};
