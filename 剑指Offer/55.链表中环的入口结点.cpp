/*
	题目描述：
	给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
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
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(pHead==NULL|| pHead->next==NULL) return NULL;
        ListNode* fast=pHead->next;
        ListNode* slow=pHead;
        while(fast!=NULL){
            slow->next=NULL;
            slow=fast;
            fast=fast->next;
        }
        return slow;
    }
};