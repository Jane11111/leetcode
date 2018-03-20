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
    if(!l1)
        return l2;
    if(!l2)
        return l1;

    if(l1->val<l2->val){
        l1->next=mergeTwoLists(l1->next,l2);
        return l1;
    }else{
        l2->next=mergeTwoLists(l1,l2->next);
        return l2;
    }

}