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
        auto cmp = [](ListNode*a, ListNode*b){return a->val > b->val;} ;
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq;
        for(auto head: lists)
        {
            if(head)
                pq.push(head);
        }
        ListNode* dummyhead = new ListNode();
        ListNode* result = dummyhead;
        while(!pq.empty())
        {
            ListNode* cur = pq.top();
            pq.pop();
            if(cur->next) pq.push(cur->next);
            result->next = cur;
            result = result->next;
        }
        return dummyhead->next;
    }
};