/*
	题目描述：
	输入两个链表，找出它们的第一个公共结点。
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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        int len1=0, len2=0;
        ListNode *temp1 = pHead1, *temp2 = pHead2;
        while(temp1){
            len1++;
            temp1 = temp1->next;
        }
        while(temp2){
            len2++;
            temp2 = temp2->next;
        }
        if(len1>len2){
            for(int i=0; i<len1-len2; i++)
                pHead1 = pHead1->next;
        }
        else for(int i=0; i<len2-len1; i++)
                pHead2 = pHead2->next;
        while(pHead1!=pHead2 && pHead1 && pHead2){
            pHead1 = pHead1->next;
            pHead2 = pHead2->next;
        }
        return pHead1;
    }
};