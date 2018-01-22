#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
void PrintList(ListNode* head);
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

int main() {
    ListNode l1(2);
    (&l1)->next=new ListNode(4);
    (&l1)->next->next=new ListNode(3);

    ListNode l2(5);
    ListNode *t3=new ListNode(6);
    ListNode *t4=new ListNode(4);
    (&l2)->next=t3;
    t3->next=t4;

    ListNode* result=addTwoNumbers(&l1,&l2);
    PrintList(result);

}

void PrintList(ListNode* head){
    ListNode* p=head;
    while(p!=NULL){
        cout<<p->val<<endl;
        p=p->next;
    }
}


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode head(0);
    ListNode* p=&head;
    int left=0;
    while(l1!=NULL){
        int val=l1->val+l2->val+left;
        left=val/10;
        ListNode *newNode=new ListNode(val%10);
        l1=l1->next;
        l2=l2->next;
        p->next=newNode;
        p=p->next;
    }
    if(left!=0){
        p->next=new ListNode(left);
    }
    return (&head)->next;
}