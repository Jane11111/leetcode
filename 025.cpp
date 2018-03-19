#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode*next;
    ListNode(int x):val(x),next(NULL){}
};

ListNode* reverseKGroup(ListNode* head, int k);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

ListNode* reverseKGroup(ListNode* head, int k) {

    if(!head||k<=1)
        return head;

    ListNode* new_head=new ListNode(1);
    new_head->next=head;


    ListNode* last_tail=new_head;
    ListNode* first_p=head;
    ListNode* second_p=head;
    ListNode* third_p=head;

    while(third_p){
        ListNode* p=third_p;
        ListNode* will_be_tail=third_p;

        int count=0;
        while(count<k&&p){
            p=p->next;
            count++;
        }
        if(count<k) {
                last_tail->next=third_p;
            break;
        }

        first_p=third_p;
        second_p=first_p->next;
        third_p=second_p->next;
        first_p->next=p;
        count=1;
        while(count<k){

            second_p->next=first_p;
            count++;
            if(count>=k)
                break;
            first_p=second_p;
            second_p=third_p;
            third_p=third_p->next;


        }

        last_tail->next=second_p;
        last_tail=will_be_tail;
    }

    return new_head->next;


}