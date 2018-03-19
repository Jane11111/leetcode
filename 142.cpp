#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};
ListNode *detectCycle(ListNode *head);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

ListNode *detectCycle(ListNode *head) {

    map<ListNode*,bool> mymap;
    while(head){
        if(mymap.find(head)!=mymap.end())
            return head;
        mymap[head]=true;
        head=head->next;
    }
    return NULL;
}