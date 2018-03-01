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
    //简化代码
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int a,b,over=0,sum;
        ListNode head(0), *tail=&head;
        
        while (l1||l2||over) {
            if (l1) {a=l1->val; l1=l1->next;}
            else a=0;            
            if (l2) {b=l2->val; l2=l2->next;}
            else b=0;
            
            sum=a+b+over;
            over=sum/10;
            
            tail->next=new ListNode(sum%10);
            tail=tail->next;
        }
        
        return head.next;
    }
};

class Solution2 {
public:
    //即使long long长度也不够，不能转化成整数来做
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int a,b,over=0,sum;
        ListNode *head=NULL, *tail=NULL, *tmp;
        
        while (l1||l2) {
            if (l1) {a=l1->val; l1=l1->next;}
            else a=0;
            
            if (l2) {b=l2->val; l2=l2->next;}
            else b=0;
            
            sum=a+b+over;
            over=sum>=10?1:0;
            sum=over?sum-10:sum;
            
            tmp=(ListNode *)malloc(sizeof(ListNode));
            tmp->val=sum;
            tmp->next=NULL;            
            if (tail==NULL) head=tmp;
            else tail->next=tmp;
            tail=tmp;
        }
        
        if (over) {
            tmp=(ListNode *)malloc(sizeof(ListNode));
            tmp->val=over;
            tmp->next=NULL;
            tail->next=tmp;
            tail=tmp;
        }
        
        return head;
    }
};

class Solution1 {
public:
    //即使long long长度也不够，不能转化成整数来做
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string s1,s2;
        long long a,b;//int不够
        ListNode *head=NULL, *tmp;
        for (ListNode* p=l1; p!=NULL; p=p->next) s1+=p->val+'0';
        for (ListNode* p=l2; p!=NULL; p=p->next) s2+=p->val+'0';
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        a=atoll(s1.c_str());
        b=atoll(s2.c_str());
        s1=to_string(a+b);
        for (auto it : s1) {
            tmp=(ListNode *)malloc(sizeof(ListNode));
            tmp->val=it-'0';
            tmp->next=head;
            head=tmp;
        }
        return head;
    }
};
