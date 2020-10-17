
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        ListNode* tail = ans;
        int sum = 0;
        while (1 || sum)
        {
            if (l1 != NULL) sum += l1->val;
            if (l2 != NULL) sum += l2->val;

            tail->next = new ListNode(sum % 10);
            sum /= 10;

            if(l1 != NULL)
                l1 = l1->next;
            if (l2 != NULL)
                l2 = l2->next;
            tail = tail->next;
            if(l1 == NULL && l2== NULL && sum ==0) break;
        }
        return ans->next;
    }
};