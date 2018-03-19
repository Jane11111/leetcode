#include <iostream>
#include <vector>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}

};
ListNode* partition(ListNode* head, int x);
int main() {
    ListNode* p1=new ListNode(2);
    ListNode* p2=new ListNode(1);
    p1->next=p2;
    int x=1;
    ListNode* res=partition(p1,x);
    if(res)
        cout<<res->val<<endl;
    return 0;
}

ListNode* partition(ListNode* head, int x) {

    ListNode* new_head=new ListNode(1);
    new_head->next=head;

    ListNode* last_less=new_head;
    ListNode* p=head;
    ListNode* pre=new_head;
    while(p){
        if(p->val<x){
            if(last_less->next==p) {
                last_less=p;
                pre=p;
                p=p->next;
                continue;
            }
            pre->next=p->next;
            p->next=last_less->next;
            last_less->next=p;
            last_less=p;
            p=pre->next;

        }else{
            pre=p;
            p=p->next;
        }

    }
    return new_head->next;

}