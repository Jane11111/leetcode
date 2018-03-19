#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};
struct cmp{
    bool operator()(pair<ListNode*,int>& a,pair<ListNode*,int>& b){
        return a.first->val>b.first->val;
    }
};
ListNode* mergeKLists(vector<ListNode*>& lists);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.empty())
        return NULL;

    ListNode* head=new ListNode(1);
    ListNode* cur=head;
    priority_queue<pair<ListNode*,int>,vector<pair<ListNode*,int>>,cmp> myqueue;
    for(int i=0;i<lists.size();i++){
        if(lists[i]==NULL)
            continue;
        myqueue.push(pair<ListNode*,int>(lists[i],i));
        lists[i]=lists[i]->next;

    }

    while(!myqueue.empty()){
        pair<ListNode*,int> pair=myqueue.top();
        myqueue.pop();
        ListNode* p=pair.first;
        int index=pair.second;
        cur->next=p;
        cur=cur->next;

        if(lists[index]){
            pair.first=lists[index];
            myqueue.push(pair);
            lists[index]=lists[index]->next;
        }
    }
    return head->next;


}