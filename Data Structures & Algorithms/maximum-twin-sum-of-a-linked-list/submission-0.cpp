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
    int pairSum(ListNode* head) {
        ListNode *fast = head, *slow = head;
        stack<int> st;

        while(fast){
            int value = slow->val;
            st.push(value);

            fast = fast->next->next;
            slow = slow->next;
        }
        int maxTwinSum = 0;
        while(slow){
            int value1 = st.top();
            st.pop();
            int value2 = slow->val;

            maxTwinSum = max(maxTwinSum, value1+value2);
            slow = slow->next;
        }

        return maxTwinSum;
    }
};