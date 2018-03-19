#include <iostream>
#include <vector>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};
ListNode* swapPairs(ListNode* head);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

ListNode* swapPairs(ListNode* head) {

    ListNode* new_head=new ListNode(1);
    new_head->next=head;
    ListNode* last_tail=new_head;

    ListNode*p=head;
    while(p){
        ListNode* first_p=p;
        ListNode* second_p=first_p->next;
        if(!second_p)
            break;
        ListNode* third_p=second_p->next;

        second_p->next=first_p;
        first_p->next=third_p;
        last_tail->next=second_p;
        last_tail=first_p;
        p=third_p;
    }
    return new_head->next;
}