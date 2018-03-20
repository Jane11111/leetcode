#include <iostream>
#include <vector>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* new_head=new ListNode(1);
    ListNode* cur=new_head;
    while(l1||l2){

            if(l1&&l2&&l1->val<l2->val||l1&&!l2){
                cur->next=l1;
                l1=l1->next;
                cur=cur->next;
            }else{
                cur->next=l2;
                l2=l2->next;
                cur=cur->next;
            }

    }
    return new_head->next;

}