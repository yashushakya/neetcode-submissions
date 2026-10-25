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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,
        greater<pair<int,ListNode*>>> pq;

        for(ListNode* node: lists){
            while(node){
                pq.push({node->val,node});
                node=node->next;
            }
        }
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        while(!pq.empty()){
            ListNode* node = pq.top().second;
            temp->next = node;
            temp = temp->next;
            pq.pop();
        }

        return dummyNode->next;
        
    }
};
