#include <iostream>
#include <vector>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};
void reorderList(ListNode* head);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

void reorderList(ListNode* head) {

    vector<ListNode*> vec;
    while(head){
        vec.push_back(head);
        head=head->next;
    }

    int i=0;
    int j=vec.size()-1;
    while(i<=j){
        ListNode* p1=vec[i];
        ListNode* p2=vec[j];
        if(i==j-1){
            p1->next=p2;
            p2->next=NULL;
            break;
        }else if(i==j){
            p1->next=NULL;
            break;
        }

        p1->next=p2;
        p2->next=vec[i+1];


        i++;
        j--;
    }

}