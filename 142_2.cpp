#include <iostream>
#include <vector>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};
ListNode *detectCycle(ListNode *head);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

ListNode *detectCycle(ListNode *head){

    if(!head||!head->next)
        return NULL;

    ListNode*p1=head;
    ListNode*p2=head;
    while(p2){

        p1=p1->next;

        p2=p2->next;
        if(p2->next)
            p2=p2->next;
        else
            return NULL;

        if(p2==p1)
            break;
    }
    p1=head;
    while(p2!=p1){
        p1=p1->next;
        p2=p2->next;

    }
    return p1;

}