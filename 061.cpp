#include <iostream>
#include <vector>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};
ListNode* rotateRight(ListNode* head, int k);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

ListNode* rotateRight(ListNode* head, int k) {
    if(head==NULL)
        return NULL;

    int len=1;
    ListNode*p=head;//p是tail
    while(p->next){
        len++;
        p=p->next;
    }

    if(k>=len)
        return head;
    ListNode* cur=head;
    while(len-k>1){
        cur=cur->next;
        k++;
    }
    p->next=head;
    ListNode* new_head=cur->next;
    cur->next=NULL;
    return new_head;

}