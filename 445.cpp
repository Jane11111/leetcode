#include <iostream>
#include <vector>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    vector<int> n1;
    vector<int> n2;
    while(l1){
        n1.push_back(l1->val);
        l1=l1->next;
    }
    while(l2){
        n2.push_back(l2->val);
        l2=l2->next;
    }


    int i1=n1.size()-1;
    int i2=n2.size()-1;
    int left=0;
    ListNode* last_head=NULL;
    ListNode* cur=NULL;
    while(i1>=0||i2>=0||left){
        int t1=0;
        int t2=0;
        if(i1>=0){
            t1=n1[i1];
            i1--;
        }
        if(i2>=0){
            t2=n2[i2];
            i2--;
        }
        int res=t1+t2+left;
        left=res/10;
        res=res%10;
        cur=new ListNode(res);
        cur->next=last_head;
        last_head=cur;

    }
    if(!cur)
        cur=new ListNode(0);
    return cur;

}