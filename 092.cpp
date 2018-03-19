#include <iostream>
#include <vector>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){};
};
ListNode* reverseBetween(ListNode* head, int m, int n);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

ListNode* reverseBetween(ListNode* head, int m, int n){

    if(m==n)
        return head;



    ListNode* new_head=new ListNode(1);
    new_head->next=head;

    int count=0;
    ListNode* pre=new_head;
    ListNode* cur=new_head;
    ListNode* tail=NULL;
    ListNode* p1=NULL;
    ListNode* p2=NULL;
    while(count<=n){
        if(count==m-1)
            tail=cur;
        else if(count==m){
            p1=cur;
        }
        if(count>m&&count<=n){
            if(count==n)
                p2=cur;
            ListNode* tmp=cur->next;
            cur->next=pre;
            pre=cur;
            cur=tmp;
            count++;
            continue;

        }

        pre=cur;
        cur=cur->next;
        count++;
    }

    p1->next=cur;
    tail->next=p2;
    return new_head->next;




}