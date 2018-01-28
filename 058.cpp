#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x),next(NULL){}
};
ListNode* insertionSortList(ListNode* head);

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

ListNode* insertionSortList(ListNode* head) {
    if(head==NULL)
        return NULL;
    ListNode* pre=head;
    ListNode* cur=head->next;
    ListNode* tmp_pre;
    ListNode* tmp_cur;

    while(cur!=NULL){
        tmp_pre=NULL;
        tmp_cur=head;
        int val=cur->val;

        //这个循环找到当前应该插入的位置，即tmp指向前面
        while(tmp_cur->val < val&&tmp_cur!=cur){
            tmp_cur=tmp_cur->next;
            if(tmp_pre==NULL)
                tmp_pre=head;
            else
                tmp_pre=tmp_pre->next;

        }
        //处理tmp的各种情况
        if(tmp_cur==head){
            ListNode* to_move=cur;
            pre->next=cur->next;
            cur=cur->next;//cur右移

            to_move->next=head;
            head=to_move;

        }else if(tmp_cur==cur){
            pre=pre->next;
            cur=cur->next;
        }else{
            ListNode* to_move=cur;
            pre->next=cur->next;
            cur=cur->next;

            tmp_pre->next=to_move;
            to_move->next=tmp_cur;
        }
    }
    return head;



}