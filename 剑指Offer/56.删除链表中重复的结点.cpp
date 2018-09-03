/*
	题目描述：
	在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
*/
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        ListNode* head=new ListNode(0);
        ListNode* p=head;
        ListNode* q=pHead;
        while(q){
            while(q!=NULL&&q->next!=NULL&&q->next->val==q->val){
                int tmp=q->val;
                while(q!=NULL&&q->val==tmp)
                    q=q->next;
            }
            p->next=q;
            p=p->next;
            if(q)
                q=q->next;
        }   
        return head->next;
    }
};