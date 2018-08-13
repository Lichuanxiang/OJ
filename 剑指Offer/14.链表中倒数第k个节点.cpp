/*
	题目描述：
	输入一个链表，输出该链表中倒数第k个结点。
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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead==NULL||k==0) return NULL;
        ListNode* kth_node = pListHead;
        for(int i=0; i<k-1; i++){
            if(kth_node->next!=NULL) kth_node = kth_node->next;
            else return NULL;
        }
        for(; kth_node->next!=NULL; kth_node = kth_node->next, pListHead = pListHead->next);
        return pListHead;
    }
};