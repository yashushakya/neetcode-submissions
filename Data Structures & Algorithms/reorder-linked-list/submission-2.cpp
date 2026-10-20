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
    void reorderList(ListNode* head) {

        if(!head || !head->next) return;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* last = head;

        while(fast && fast->next){
            last = slow;
            slow= slow->next;
            fast = fast->next->next;
        }

        last->next = nullptr;
        ListNode* prev = nullptr;
        ListNode* front = nullptr;
        ListNode* temp = slow;

        while(temp){
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        ListNode* secondHead = prev;

        temp = head;
        while(temp && secondHead){
            ListNode* front1 = temp->next;
            ListNode* front2 = secondHead->next;
            temp->next = secondHead;
            temp = front1;
            if(front1){
                secondHead->next = front1;
                secondHead = front2;
            }            
            
        }      
      
        
    }
};
