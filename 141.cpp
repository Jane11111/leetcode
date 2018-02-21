#include <iostream>
#include <map>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}

};
bool hasCycle(ListNode *head);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


bool hasCycle(ListNode *head) {
    map<ListNode*,bool> my_map;
    while(head!=NULL){
        if(my_map.count(head)!=0)
            return true;
        my_map[head]=true;
        head=head->next;
    }
    return false;

}