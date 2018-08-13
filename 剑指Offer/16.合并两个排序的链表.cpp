/*
	题目描述：
	输入两个单调递增的链表，输出两个链表合成后的链表，
    当然我们需要合成后的链表满足单调不减规则。
*/
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode* newlist= new ListNode(0);
        ListNode* newnode = newlist;
        while( pHead1 && pHead2 ){
            if(pHead1->val < pHead2->val){
                newnode->next = pHead1;
                newnode = newnode->next;
                pHead1 = pHead1->next;
            }
            else{
                newnode->next = pHead2;
                newnode = pHead2;
                pHead2 = pHead2->next;
            }
        }
        if(pHead1) newnode->next = pHead1;
        if(pHead2) newnode->next = pHead2;
        return newlist->next;
    }
};