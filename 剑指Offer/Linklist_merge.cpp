//Á´±íºÏ²¢
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):
        val(x), next(NULL){}
};

class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode* newnode = new ListNode(-1);
        ListNode* newlist = newnode;
        while(pHead1 && pHead2){
            if(pHead1->val<pHead2->val){
                newnode->next = pHead1;
                newnode = pHead1;
                pHead1 = pHead1->next;
            }
            else{
                newnode->next = pHead2;
                newnode = pHead2;
                pHead2 = pHead2->next;
            }
        }
        if(pHead1!=NULL) newnode->next = pHead1;
        if(pHead2!=NULL) newnode->next = pHead2;
        return newlist->next;
    }
};
//class Solution {
//public:
//    void push(int value) {
//        if(!s_data.empty()&&!s_help.empty()){
//            s_data.push(value);
//            if(value<s_help.top()) s_help.push(value);
//            else s_help.push(s_help.top());
//        }
//        else{
//            s_data.push(value);
//            s_help.push(value);
//        }
//    }
//    void pop() {
//        if(!s_data.empty()&&!s_help.empty()){
//            s_data.pop();
//            s_help.pop();
//        }
//    }
//    int top() {
//        if(!s_data.empty())
//            return s_data.top();
//        else return -1;
//    }
//    int min() {
//        return s_help.top();
//    }
//private:
//    stack<int> s_data;
//    stack<int> s_help;
//};

int main(){
    Solution sol;
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(3);
    a->next = c;
    for(int i=4; i<6; i++){
        ListNode* d = new ListNode(i);
        c->next = d;
        c = c->next;
    }
    ListNode* f = new ListNode(6);
    b->next = f;
    for(int i=7; i<10; i++){
        ListNode* e = new ListNode(i);
        f->next = e;
        f = f->next;
    }

    ListNode* g = sol.Merge(a,b);

    for(; g!=NULL; g = g->next)
        printf("%d ",g->val);
    printf("\n");

    return 0;
}
