/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    //快慢指针。当两指针相遇时，用一个指针从头除法，另外一个指针从相遇点出发，
    //则最后两个指针会在成环点相遇。结论的推导可以看下别人的博客。
    ListNode *detectCycle(ListNode *head) {
        if (!head) return NULL;
        ListNode *slow=head, *fast=head;
        while (slow&&fast) {
            //先移动，再判断；上一题是先判断再移动。
            slow=slow->next;
            fast=fast->next;
            if (fast) fast=fast->next;
            //还要判断是否为空
            if (slow==fast&&slow) {
                while (head!=slow) {
                    head=head->next;
                    slow=slow->next;
                }
                return head;
            }
        }
        return NULL;
    }
};

class Solution1 {
public://hash
    ListNode *detectCycle(ListNode *head) {
        set<ListNode*> hash;//不能用val做hash映射因为有重复值
        while (head) {
            auto it=hash.find(head);
            if (it!=hash.end()) return head;
            hash.insert(head);
            head=head->next;
        }
        return NULL;
    }
};
