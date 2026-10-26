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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int carry =0;
        int add =0;
        ListNode* dummyNode = new ListNode();
        ListNode* temp = dummyNode;
        while(l1 || l2 || carry){
            int num1 = 0;
            int num2 = 0;
            if(l1) {
                num1 = l1->val;
                l1 = l1->next;
            }
            if(l2) {
                num2 = l2->val;
                l2 = l2->next;
            }
            add = (num1+num2+carry);
            carry = (num1+num2+carry)/10;
            ListNode* node = new ListNode(add%10);
            temp->next = node;
            temp = node;
        }

        return dummyNode->next;
        
    }
};
