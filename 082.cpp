#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};
ListNode* deleteDuplicates(ListNode* head);
int main() {
    ListNode* p1=new ListNode(1);
    ListNode* p2=new ListNode(1);
    ListNode* p3=new ListNode(2);
    p2->next=p3;
    p1->next=p2;
    ListNode* res=deleteDuplicates(p1);
    if(res)
        cout<<res->val;
}

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* new_head=new ListNode(1);
    new_head->next=head;
    ListNode* pre=new_head;

    ListNode* p=head;
    while(p){

        int num=p->val;
        ListNode* tmp=p->next;
        if(tmp&&tmp->val==num){
            while(tmp&&tmp->val==num)
                tmp=tmp->next;
            pre->next=tmp;
            p=tmp;
        }else{
            pre=p;
            p=p->next;
        }
    }
    return new_head->next;

}