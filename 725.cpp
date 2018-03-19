#include <iostream>
#include <vector>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};
vector<ListNode*> splitListToParts(ListNode* root, int k);
int main() {
    ListNode*p1=new ListNode(1);
    ListNode*p2=new ListNode(2);
    ListNode*p3=new ListNode(3);
    ListNode*p4=new ListNode(4);
    p1->next=p2;
    p2->next=p3;
    p3->next=p4;
    int k=5;
    vector<ListNode*> res=splitListToParts(p1,k);
    cout<<res.size()<<endl;
}

vector<ListNode*> splitListToParts(ListNode* root, int k) {

    int count=0;
    ListNode*p=root;
    while(p){
        count++;
        p=p->next;
    }

    int n1=count/k;
    int n2=count%k;

    vector<ListNode*> res;
    p=root;
    while(p){

        int size=n1;
        if(n2){
            size++;
            n2--;
        }

        int num=1;
        ListNode*tmp=p;
        while(num<size){
            tmp=tmp->next;
            num++;
        }
        res.push_back(p);
        p=tmp->next;
        tmp->next=NULL;

    }



    while(res.size()<k)
        res.push_back(NULL);
    return res;



}