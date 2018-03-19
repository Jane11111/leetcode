#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};
ListNode* MergeSort(ListNode* head,int n);
ListNode* Merge(ListNode* h1,ListNode* h2,int n1,int n2);
ListNode* sortList(ListNode* head);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

ListNode* MergeSort(ListNode* head,int n){
    if(n==1)
        head->next=NULL;
    if(n<=1)
        return head;
    int m=n/2;
    int count=0;
    ListNode* p=head;
    while(count<m){
        count++;
        p=p->next;
    }
    ListNode* p1=MergeSort(head,m);
    ListNode* p2=MergeSort(p,n-m);
    ListNode* new_head=Merge(p1,p2,m,n-m);
    return new_head;

}
ListNode* Merge(ListNode* h1,ListNode* h2,int n1,int n2){

    ListNode* new_head=new ListNode(1);
    ListNode* p=new_head;
    while(n1>0||n2>0){
        if(n1>0&&n2>0){
            if(h1->val<h2->val){
                p->next=h1;
                h1=h1->next;
                n1--;
            }else{
                p->next=h2;
                h2=h2->next;
                n2--;
            }
        }else if(n1>0){
            p->next=h1;
            h1=h1->next;
            n1--;
        }else{
            p->next=h2;
            h2=h2->next;
            n2--;
        }
        p=p->next;
    }
    return new_head->next;

}

ListNode* sortList(ListNode* head) {

    int count=0;
    ListNode* p=head;
    while(p){
        p=p->next;
        count++;
    }
    ListNode* new_head=MergeSort(head,count);
    return new_head;
}