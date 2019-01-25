/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public://快慢指针，先移动再判断
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        ListNode *slow=head, *fast=head;
        while (slow&&fast) {
            //移动
            slow=slow->next;
            fast=fast->next;
            if (fast) fast=fast->next;
            //判断，注意判断非空
            if (slow==fast&&slow) return true;
        }
        return false;
    }
};

class Solution2 {
public://快慢指针，先判断再移动
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        ListNode *p1=head, *p2=head->next;
        while (p1&&p2) {
            if (p1==p2) return true;
            p1=p1->next;
            p2=p2->next;
            if (p2) p2=p2->next;
        }
        return false;
    }
};

class Solution1 {
public://hash
    bool hasCycle(ListNode *head) {
        //if (!head) return false;
        set<ListNode*> hash;//不能用val做hash映射因为有重复值
        while (head) {
            auto it=hash.find(head);
            if (it!=hash.end()) return true;
            hash.insert(head);
            head=head->next;
        }
        return false;
    }
};
