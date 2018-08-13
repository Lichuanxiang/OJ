/*
	题目描述：
	输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
*/
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> v;
        for(ListNode* node=head; node!=NULL; node = node->next)
            v.push_back(node->val);
        for(int i=0; i<v.size()/2; i++){
            int temp = v[i];
            v[i] = v[v.size()-1-i];
            v[v.size()-1-i] = temp;
        }
        return v;
    }
};