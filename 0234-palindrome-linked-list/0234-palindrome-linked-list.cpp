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
ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
         if (!head || !head->next) return true;
        ListNode* slow = head;
        ListNode* fast =head;

        while(fast!= nullptr && fast->next != nullptr)
        {
            slow= slow->next;
            fast = fast->next->next;
        }

        slow->next = reverseList(slow->next);

        ListNode* first = head;
        ListNode* second = slow->next;


        while(second)
        {
            if(first->val != second->val)
            {
                return false;
            }
            first = first->next;
            second = second->next;
        }

        return true;


       
    }
};