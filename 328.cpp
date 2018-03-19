#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x),next(NULL){}
};

ListNode* oddEvenList(ListNode* head);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

ListNode* oddEvenList(ListNode* head) {

    if(!head||!head->next)
        return head;

    ListNode* last_odd=head;
    ListNode* pre=last_odd->next;
    ListNode* cur=pre->next;
    while(cur){
        pre->next=cur->next;
        cur->next=last_odd->next;
        last_odd->next=cur;
        last_odd=cur;
        pre=pre->next;
        if(pre)
            cur=pre->next;
        else
            cur=pre;
    }
    return head;

}