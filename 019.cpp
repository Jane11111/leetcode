#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};
ListNode* removeNthFromEnd(ListNode* head, int n);
int main() {
    ListNode *p1=new ListNode(1);
    ListNode *p2=new ListNode(2);
    ListNode *p3=new ListNode(3);
    ListNode *p4=new ListNode(4);
    ListNode *p5=new ListNode(5);
    p1->next=p2;
    p2->next=p3;
    p3->next=p4;
    p4->next=p5;
    ListNode*head=removeNthFromEnd(p1,2);
    while(head){
        cout<<head->val<<endl;
        head=head->next;
    }
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
    int count=0;
    ListNode *p=head;
    while(p!=NULL){
        count++;
        p=p->next;
    }
    n=count-n;
    if(n==0)
        head=head->next;
    else if(n<count){
        p=head;
        count=1;
        while(count!=n){
            count++;
            p=p->next;
        }
        p->next=p->next->next;
    }
    return head;

}